

execute_pipeline() {
	# Le premier argument est la profondeur actuelle (défaut à 0), le deuxième est le programme courant,
	# les suivants constituent la suite.
	local depth="${1:-0}"
	local max=${#progs[@]}

	local prog="${progs[$depth]}"
	local duration="${durations[$depth]}"
	local mem_test="${mem_tests[$depth]}"
	local err_test="${err_tests[$depth]}"
	local fail_test="${fail_tests[$depth]}"

	local pg_out_expected="${out_expected[$depth]}"
	local pg_err_expected="${err_expected[$depth]}"

	if [ "$DEBUG_MODE" = true ]; then
		printf "\n\n($depth) $prog\n"
	fi

	pg_executed_progs+=("$prog")
	# Créer des fichiers temporaires pour capturer les sorties.
	local stdout_file stderr_file

	# stdout_file=$(mktemp /tmp/stdout_file_${depth}_XXXXXX)
	# stderr_file=$(mktemp /tmp/stderr_file_${depth}_XXXXXX)

	# /dev/shm est en ram.... environs 100x plus rapide que /tmp
	local stdout_file="/dev/shm/stdout_file_${depth}"
	local stderr_file="/dev/shm/stderr_file_${depth}"

	local PROG_ARGS

	if [ "$quoted" = "quoted" ]; then
		PROG_ARGS="${PG_ARGS[$depth]}"
		PROG_ARGS__=( "$PROG_ARGS" )
	else
		PROG_ARGS="${PG_ARGS[$depth]}"
		IFS=' ' read -r -a PROG_ARGS__ <<< "$PROG_ARGS"
	fi

	# set -x
	# if [ "$mem_test" = "mem" ]; then
	# 	local valgrind_log_file=$(mktemp /tmp/valgrind_logfile_${depth}_XXXXXX)
	# 	if [ "$DEBUG_MODE" = true ]; then
	# 		printf "Valgrind wanted\n"
	# 	fi
	# 	timeout "$duration" \
	# 	valgrind --log-file="$valgrind_log_file" -s --leak-check=full --error-exitcode=99 \
	# 		"$prog" "${PROG_ARGS__[@]}" \
	# 		> >(tee "$stdout_file" > /dev/null) \
	# 		2> >(tee "$stderr_file" > /dev/null) &
	# else
	# 	if [ "$DEBUG_MODE" = true ]; then
	# 		printf "No Valgrind wanted\n"
	# 	fi
	# 	timeout "$duration" \
	# 		"$prog" "${PROG_ARGS__[@]}" \
	# 		> >(tee "$stdout_file" > /dev/null) \
	# 		2> >(tee "$stderr_file" > /dev/null) &
	# fi
	if [ "$mem_test" = "mem" ]; then
		# local valgrind_log_file=$(mktemp /tmp/valgrind_logfile_${depth}_XXXXXX)
		local valgrind_log_file="/dev/shm/valgrind_logfile_${depth}"
		if [ "$DEBUG_MODE" = true ]; then
			printf "Valgrind wanted\n"
		fi
		timeout "$duration" \
		valgrind --log-file="$valgrind_log_file" -s --leak-check=full --error-exitcode=99 \
			"$prog" "${PROG_ARGS__[@]}" \
			> "$stdout_file" \
			2> "$stderr_file"
	else
		if [ "$DEBUG_MODE" = true ]; then
			printf "No Valgrind wanted\n"
		fi
		timeout "$duration" \
			"$prog" "${PROG_ARGS__[@]}" \
			> "$stdout_file" \
			2> "$stderr_file"
	fi
	# set +x
	local pid_prog=$!


	# Si on ne redirige pas la sortie d'erreur, certaines peuvent s'afficher dans le terminal.
	wait "$pid_prog" 2>/dev/null
	local pg_exit_code=$?

	pg_exit_code_recup+=("$pg_exit_code")

	local pg_out_content pg_err_content

	# pg_out_content=$(cat "$stdout_file")
	# pg_err_content=$(cat "$stderr_file")
	while IFS= read -r line; do
		pg_out_content+=("$line")
	done < "$stdout_file"

	while IFS= read -r line; do
		pg_err_content+=("$line")
	done < "$stderr_file"
	pg_stdout_recup+=("$pg_out_content")
	pg_stderr_recup+=("$pg_err_content")

	local ret_err
	local ret_mem
	local ret_fail

	ret_mem=false
	ret_err=false
	if [ "$mem_test" = "mem" ] || [ "$err_test" = "err" ]; then
		test_prog_err "$pg_exit_code" "$valgrind_log_file"
	fi
	pg_mem_recup+=("$ret_mem")
	pg_err_recup+=("$ret_err")


	ret_fail=null
	if [ "$ret_mem" = false ] && [ "$ret_err" = false ]; then
		ret_fail=$( [[ "$pg_out_content" =~ ${out_expected[$depth]} && "$pg_err_content" =~ ${err_expected[$depth]} ]] && echo false || echo true )
	fi
	pg_fail_recup+=("$ret_fail")

	if [ "$ret_mem" = false ] && [ "$ret_err" = false ] && [ "$ret_fail" = false ]; then
		pg_failure_detected_recup+=(false)
	else
		pg_failure_detected_recup+=(true)
	fi

	local next=$(( depth + 1 ))
	if [ "$next" -lt "$max" ] && [ "$ret_mem" = false ] && [ "$ret_err" = false ] && [ "$ret_fail" = false ]; then
		execute_pipeline "$next" < "$stdout_file"
	fi



	rm -f "$stdout_file" "$stderr_file" "$valgrind_log_file"
}



core_test() {

	local quoted="$1"

	local progs=()
	local durations=()
	local mem_tests=()
	local err_tests=()
	local fail_tests=()
	local out_expected=()
	local err_expected=()

	local pg_mem_recup=()
	local pg_err_recup=()
	local pg_fail_recup=()
	local pg_exit_code_recup=()
	pg_stdout_recup=()
	pg_stderr_recup=()
	pg_executed_progs=()
	pg_failure_detected_recup=()

	# Parcours de PG_PARAMS par pas de 7
	for (( pg_param=0; pg_param<${#PG_PARAMS[@]}; pg_param+=7 )); do
		progs+=("${PG_PARAMS[pg_param]}")
		durations+=("${PG_PARAMS[pg_param+1]}")
		mem_tests+=("${PG_PARAMS[pg_param+2]}")
		err_tests+=("${PG_PARAMS[pg_param+3]}")
		fail_tests+=("${PG_PARAMS[pg_param+4]}")
		out_expected+=("${PG_PARAMS[pg_param+5]}")
		err_expected+=("${PG_PARAMS[pg_param+6]}")
	done

	TEST_NUMBER=$((TEST_NUMBER + 1))
	LOCAL_TEST_NUMBER=$((LOCAL_TEST_NUMBER + 1))

	TEST_ID=$(printf "%04d" "$TEST_NUMBER")

	if [ -n "$PG_STDINS" ]; then
		if [ "$PG_STDINS" = $'\x04' ]; then
			execute_pipeline 0 < /dev/null
		else
			execute_pipeline 0 <<< "$PG_STDINS"
		fi
	else
		execute_pipeline 0
	fi

	local i=0;
	for prog in "${pg_executed_progs[@]}"; do
		local pg_out_expected="${out_expected[$i]}"
		local pg_err_expected="${err_expected[$i]}"
		local pg_out_content="${pg_stdout_recup[$i]}"
		local pg_err_content="${pg_stderr_recup[$i]}"
		local pg_exit_code="${pg_exit_code_recup[$i]}"
		local pg_err="${pg_err_recup[$i]}"
		local pg_mem="${pg_mem_recup[$i]}"
		local pg_fail="${pg_fail_recup[$i]}"

		if [ "$pg_fail" = true ]; then
			trace_fail "Fail"
		elif [ "$pg_fail" = false ]; then
			trace_ok
		fi

		i=$(( i + 1 ))
	done

	if ! [[ " ${pg_err_recup[*]} " =~ " true " ]] && ! [[ " ${pg_mem_recup[*]} " =~ " true " ]]; then
		if [[ " ${pg_fail_recup[*]} " =~ " true " ]]; then
			if [ "$SHOW_MINI_OK" = true ]; then
				show_mini_res "F" "${BRYL_B}"
			fi
		elif [[ " ${pg_fail_recup[*]} " =~ " false " ]]; then
			if [ "$SHOW_MINI_OK" = true ]; then
				show_mini_res ">" "${BRGN_B}"
			fi
		else
			show_mini_res "?" "${BRBL_B}"
		fi
	fi

}
