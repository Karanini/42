limits_100_tests_only() {
	local TEST_NAME="Limits tests (size 100)"
	test_box "Limits tests 100"

	local count
	local SEQUENCES=()
	local myseed=42

	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	SHOW_MINI_OK=false

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	for i in {1..50}; do
		SEQUENCES=()
		generate_sequences 10 1 100 "$myseed"
		myseed=$(next_seed "$myseed")
		for args in "${SEQUENCES[@]}"; do
			PG_ARGS=()
			PG_ARGS+=("$args")
			PG_ARGS+=("$args")
			core_test "quoted"
			if ! [[ ${pg_failure_detected_recup[*]} =~ true ]]; then
				count=$(echo "${pg_stdout_recup[0]}" | wc -l)
				if [[ $count -lt 700 ]]; then
					show_mini_res "5" "${BRGN_B}" 
				elif [[ $count -lt 900 ]]; then
					show_mini_res "4" "${BRYL_B}"
					trace_perf 4 "(>700)" "$(IFS=" "; echo "${args[*]}")"
				elif [[ $count -lt 1100 ]]; then
					show_mini_res "3" "${BRYL_B}"
					trace_perf 3 "(>900)" "$(IFS=" "; echo "${args[*]}")"
				elif [[ $count -lt 1300 ]]; then
					show_mini_res "2" "${BRYL_B}"
					trace_perf 2 "(>1100)" "$(IFS=" "; echo "${args[*]}")"
				elif [[ $count -lt 1500 ]]; then
					show_mini_res "1" "${BRYL_B}"
					trace_perf 1 "(>1300)" "$(IFS=" "; echo "${args[*]}")"
				else
					show_mini_res "0" "${BRRD_B}"
					trace_perf 0 "(>1500)" "$(IFS=" "; echo "${args[*]}")"
				fi
			else
				show_mini_res "F" "${BRYL_B}"
			fi
		done
	done

	printf "\n"
}
