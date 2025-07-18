manage_abort_error() {

	if [ "$nb_abort_errors" -eq 0 ]; then
		err_t="Abort (SIGABRT) / $1"
	else
		err_t+=" | $1"
	fi
	show_mini_res "$2" "${BRCN_B}"
	nb_abort_errors=$(( nb_abort_errors + 1 ))
}

manage_valgrind_error() {

	if [ "$nb_valgrind_errors" -eq 0 ]; then
		err_t="Valgrind / $1"
	else
		err_t+=" | $1"
	fi
	show_mini_res "$2" "${BRMG_B}"
	nb_valgrind_errors=$(( nb_valgrind_errors + 1 ))

}

test_prog_err() {

	if [[ "$1" -eq 99 && "$mem_test" = "mem" ]]; then

		local log_file="$2"
		local nb_valgrind_errors=0

		local err_t="Valgrind / GENERAL VALGRIND ERROR"

		# Vérifier s'il y a une erreur d'accès mémoire invalide (lecture/écriture hors limites)
		if grep -iq "Invalid read" "$log_file" 2>/dev/null || grep -iq "Invalid write" "$log_file" 2>/dev/null; then
			manage_valgrind_error "INVALID MEMORY ACCESS ERROR" "M"
		fi

		# Vérifier s'il y a des fuites de mémoire définitives
		if grep -iq "definitely lost:" "$log_file" 2>/dev/null; then
			manage_valgrind_error "MEMORY LEAK ERROR" "L"
		fi

		# Vérifier l'utilisation de valeurs non initialisées
		if grep -iq "Conditional jump or move depends on uninitialised value" "$log_file" 2>/dev/null; then
			manage_valgrind_error "UNINITIALIZED VALUE ERROR" "U"
		fi

		# Vérifier les erreurs de libération (double free, invalid free, etc.)
		if grep -iq "Invalid free" "$log_file" 2>/dev/null || grep -iq "mismatched free" "$log_file" 2>/dev/null; then
			manage_valgrind_error "FREE ERROR" "F"
		fi

		# Vérifier les erreurs d'utilisation après libération (use-after-free)
		if grep -iq "use-after-free" "$log_file" 2>/dev/null; then
			manage_valgrind_error "USE AFTER FREE ERROR" "A"
		fi

		# Vérifier les erreurs de chevauchement mémoire (overlap), par exemple lors d'un memcpy avec chevauchement
		if grep -iq "overlap" "$log_file" 2>/dev/null; then
			manage_valgrind_error "MEMORY OVERLAP ERROR" "P"
		fi

		# Vérifier les erreurs liées aux paramètres système invalides
		if grep -iq "Syscall param" "$log_file" 2>/dev/null; then
			manage_valgrind_error "SYSCALL PARAMETER ERROR" "C"
		fi

		# Stack overflow detection
		if grep -iq "stack overflow" "$log_file" 2>/dev/null; then
			manage_valgrind_error "STACK OVERFLOW ERROR" "O"
		fi

		# Stack smashing detected
		if grep -iq "stack smashing detected" "$log_file" 2>/dev/null; then
			manage_valgrind_error "STACK SMASHING ERROR" "S"
		fi

		# Heap corruption errors
		if grep -iq "heap corruption" "$log_file" 2>/dev/null; then
			manage_valgrind_error "HEAP CORRUPTION ERROR" "H"
		fi

		# Race condition errors (reporting from Helgrind/DRD, par exemple)
		if grep -iq "Race condition" "$log_file" 2>/dev/null; then
			manage_valgrind_error "RACE CONDITION ERROR" "R"
		fi

		# Invalid jump errors
		if grep -iq "Invalid jump" "$log_file" 2>/dev/null; then
			manage_valgrind_error "INVALID JUMP ERROR" "J"
		fi

		if [ "$nb_valgrind_errors" -eq 0 ]; then
			show_mini_res "V" "${BRMG_B}"
		fi

		trace_fail "$err_t"

		ret_mem=true

	elif [ "$1" -eq 124 ]; then

		show_mini_res "T" "${BRBL_B}"
		trace_fail "TIMEOUT"
		ret_err=true

	elif [ "$1" -eq 126 ]; then

		show_mini_res "X" "${BRBL_B}"
		trace_fail "NOT EXECUTABLE"
		ret_err=true

	elif [ "$1" -eq 127 ]; then

		show_mini_res "N" "${BRBL_B}"
		trace_fail "FILE NOT EXISTS"
		ret_err=true

	elif [ "$1" -eq 130 ]; then
		# SIGINT

		show_mini_res "C" "${BRCN_B}"
		trace_fail "INTERRUPTED (SIGINT)"
		ret_err=true

	elif [ "$1" -eq 132 ]; then
		# SIGILL

		show_mini_res "L" "${BRCN_B}"
		trace_fail "ILLEGAL INSTRUCTION (SIGILL)"
		ret_err=true

	elif [ "$1" -eq 134 ]; then
		# SIGABRT/SIGIOT

		local log_file="$2"
		local nb_abort_errors=0

		err_t="Abort (SIGABRT) / GENERAL ABORT ERROR"

		# Vérifier les erreurs de pointeur invalide, par exemple lors d'un appel à munmap_chunk()
		if grep -iq "munmap_chunk(): invalid pointer" "$log_file" 2>/dev/null; then
			manage_abort_error "INVALID POINTER ERROR" "P"
		fi

		# Vérifier si le message "IOT instruction" apparaît (cas typique d'un abort via SIGABRT ou SIGIOT)
		if grep -iq "IOT instruction" "$log_file" 2>/dev/null; then
			manage_abort_error "IOT INSTRUCTION ERROR" "I"
		fi

		# Vérifier si le système détecte un "stack smashing" (pile corrompue)
		if grep -iq "stack smashing detected" "$log_file" 2>/dev/null; then
			manage_abort_error "STACK SMASHING ERROR" "S"
		fi

		if [ "$nb_abort_errors" -eq 0 ]; then
			show_mini_res "A" "${BRCN_B}"
		fi

		trace_fail "$err_t"

		ret_err=true

	elif [ "$1" -eq 135 ]; then
		# SIGBUS

		show_mini_res "B" "${BRCN_B}"
		trace_fail "BUS ERROR (SIGBUS)"
		ret_err=true

	elif [ "$1" -eq 136 ]; then
		# SIGFPE

		show_mini_res "F" "${BRCN_B}"
		trace_fail "FLOATING POINT EXCEPTION (SIGFPE)"
		ret_err=true

	elif [ "$1" -eq 137 ]; then
		# SIGKILL

		show_mini_res "K" "${BRCN_B}"
		trace_fail "KILLED (SIGKILL)"
		ret_err=true

	elif [ "$1" -eq 139 ]; then
		# SIGSEGV

		show_mini_res "S" "${BRCN_B}"
		trace_fail "SEGFAULT (SIGSEGV)"
		ret_err=true

	elif [ "$1" -eq 143 ]; then
		# SIGTERM
		show_mini_res "T" "${BRCN_B}"
		trace_fail "TERMINATED (SIGTERM)"
		ret_err=true

	elif [ "$1" -ge 129 ] && [ "$1" -le 192 ]; then
		# SIG
		signal_num=$(( $1 - 128 ))
		show_mini_res "?" "${BRCN_B}"
		trace_fail "TERMINATED BY $signal_num SIGNAL"
		ret_err=true

	else
		ret_err=false
	fi


}

