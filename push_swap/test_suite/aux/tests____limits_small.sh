small_limits_tests_only() {
	local TEST_NAME="Limits tests 2 and 5"
	test_box "Limits tests 2 and 5"

	local count
	local PLIST=()

	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	local i

	SHOW_MINI_OK=false

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	generate_permutations 3
	i=0
	for args in "${PLIST[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test "quoted"
			if ! [[ ${pg_failure_detected_recup[*]} =~ true ]]; then
			count=$(echo "${pg_stdout_recup[0]}" | wc -l)
			if [[ $count -le 3 ]]; then
				show_mini_res "*" "${BRGN_B}"
			else
				show_mini_res "*" "${BRRD_B}"
				trace_perf 0 "(>3)" "$(IFS=" "; echo "${args[*]}")"
			fi
		else
			show_mini_res "F" "${BRYL_B}"
		fi
		i=$(( i + 1 ))
	done

	generate_permutations 5
	i=0
	for args in "${PLIST[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test "quoted"
			if ! [[ ${pg_failure_detected_recup[*]} =~ true ]]; then
			count=$(echo "${pg_stdout_recup[0]}" | wc -l)
			if [[ $count -le 12 ]]; then
				show_mini_res "*" "${BRGN_B}"
			else
				show_mini_res "*" "${BRRD_B}"
				trace_perf 0 "(>12)" "$(IFS=" "; echo "${args[*]}")"
			fi
		else
			show_mini_res "F" "${BRYL_B}"
		fi
		i=$(( i + 1 ))
	done
	printf "\n"
}
