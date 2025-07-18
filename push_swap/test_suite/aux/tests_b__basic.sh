basic_tests_only_bonus()
{
	local TEST_NAME="Basic"
	test_box "Basic tests (checker)"
	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	SHOW_MINI_OK=true

	PG_ARGS=()
	PG_STDINS=$'\x04'

	PG_PARAMS=()
	PG_PARAMS+=("$CHECKER" 2 "null" "err" "fail" '^$' '^$')

	core_test

	PG_PARAMS=()
	PG_PARAMS+=("$CHECKER" 2 "null" "err" "fail" '^$' '^Error$')

	core_test "quoted"

	# Error
	for args in "${TEST_ARGS_1[@]}"; do
		PG_ARGS=()
		PG_ARGS+=( "$args" )
		core_test
		core_test "quoted"
	done

	PG_PARAMS=()
	PG_PARAMS+=("$CHECKER" 2 "null" "err" "fail" '^OK$' '^$')

	# OK
	for (( j=0; j<${#TEST_ARGS_4[@]}; j+=2 )); do
		local args="${TEST_ARGS_4[j]}"
		PG_STDINS=( "${TEST_ARGS_4[j+1]}" )
		PG_ARGS=()
		PG_ARGS+=( "$args" )
		core_test
		core_test "quoted"
	done



	PG_PARAMS=()
	PG_PARAMS+=("$CHECKER" 2 "null" "err" "fail" '^KO$' '^$')
	
	# KO
	for (( j=0; j<${#TEST_ARGS_5[@]}; j+=2 )); do
		local args="${TEST_ARGS_5[j]}"
		PG_STDINS=( "${TEST_ARGS_5[j+1]}" )
		PG_ARGS=()
		PG_ARGS+=( "$args" )
		core_test
		core_test "quoted"
	done

	PG_PARAMS=()
	PG_PARAMS+=("$CHECKER" 2 "null" "err" "fail" '^$' '^Error$')
	
	# Error
	for (( j=0; j<${#TEST_ARGS_6[@]}; j+=2 )); do
		local args="${TEST_ARGS_6[j]}"
		PG_STDINS=( "${TEST_ARGS_6[j+1]}" )
		PG_ARGS=()
		PG_ARGS+=( "$args" )
		core_test
		core_test "quoted"
	done

	printf "\n"
}
