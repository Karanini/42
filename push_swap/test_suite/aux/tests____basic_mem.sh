basic_mem_tests_only()
{
	local TEST_NAME="Basic mem"
	test_box "Basic mem tests (push_swap)"
	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	SHOW_MINI_OK=true

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "mem" "err" "fail" '^$' '^Error$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '.*' '^Error$')

	for args in "${TEST_ARGS_1[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test
		core_test "quoted"
	done


	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "mem" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	for args in "${TEST_ARGS_2[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test
		core_test "quoted"
	done

	printf "\n"
}
