big_num_lists_only() {
	local TEST_NAME="Big numbers"
	test_box "Big nums in lists (push_swap)"
 	local SEQUENCES=()
	local i=0

	generate_sequences 4 -2147483648 $(( -2147483649 + 2 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 5 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 50 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 100 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 200 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 300 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 400 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 500 )) 42
	generate_sequences 4 $(( 2147483648 - 2 )) 2147483647 42
	generate_sequences 4 $(( 2147483648 - 5 )) 2147483647 42
	generate_sequences 4 $(( 2147483648 - 50 )) 2147483647 42
	generate_sequences 4 $(( 2147483648 - 100 )) 2147483647 42
	generate_sequences 4 $(( 2147483648 - 200 )) 2147483647 42
	generate_sequences 4 $(( 2147483648 - 300 )) 2147483647 42
	generate_sequences 4 $(( 2147483648 - 400 )) 2147483647 42
	generate_sequences 4 $(( 2147483648 - 500 )) 2147483647 42

	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	SHOW_MINI_OK=true

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "mem" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	for args in "${SEQUENCES[@]}"; do
		if (( i % 4 == 0 )); then
			PG_ARGS=()
			PG_ARGS+=("$args")
			PG_ARGS+=("$args")
			core_test "quoted"
			core_test
		fi
		i=$(( i + 1 ))
	done

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	for args in "${SEQUENCES[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test
		i=$(( i + 1 ))
	done

	for args in "${SEQUENCES[@]}"; do
		if (( i % 4 == 0 )); then
			PG_ARGS=()
			PG_ARGS+=("$args")
			PG_ARGS+=("$args")
			core_test "quoted"
		fi
		i=$(( i + 1 ))
	done

	printf "\n"

}
