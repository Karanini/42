basic_tests_only()
{
	local TEST_NAME="Basic"
	test_box "Basic tests (push_swap)"
	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	local args=""

	SHOW_MINI_OK=true

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '^$' '^$')

	PG_ARGS=()
	PG_ARGS+=($'')
	core_test

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '^$' '^Error$')
	core_test "quoted"
	
	PG_ARGS=()
	PG_ARGS+=($'\n')
	core_test "quoted"

	for args in "${TEST_ARGS_1[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		core_test
		core_test "quoted"
	done


	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '.*' '^$')

	for args in "${TEST_ARGS_2[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		core_test
		core_test "quoted"
	done

	printf "\n"
}
