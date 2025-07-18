manage_valgrind_error() {

	if [ "$nb_valgrind_errors" -eq 0 ]; then
		err_t="Valgrind : $1"
	else
		err_t+=" | $1"
	fi
	show_mini_res "$2" "${BRRD_B}"
	nb_valgrind_errors=$(( nb_valgrind_errors + 1 ))

}

test_prog_mem() {

	if [ "$1" -eq 126 ]; then

		show_mini_res "X" "${BRCN_B}"
		trace_fail "NOT EXECUTABLE"
		ret_mem=true

	elif [ "$1" -eq 99 ]; then

		local log_file="$2"
		local nb_valgrind_errors=0

		local err_t="Valgrind : GENERAL VALGRIND ERROR"

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
			show_mini_res "V" "${BRRD_B}"
		fi

		trace_fail "$err_t"

		ret_mem=true
	else
		ret_mem=false
	fi

}