ordered_num_lists_only() {
	local TEST_NAME="Ordered lists"
	test_box "Ordered lists : 1 to 500 nums (push_swap)"

	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	SHOW_MINI_OK=true

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '^$' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	for j in $(seq 1 500); do
		args=( "$(seq 1 "$j" | tr '\n' ' ' | sed 's/[[:space:]]*$//')" )
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test "quoted"
	done

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "mem" "err" "fail" '^$' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')
	
	for j in $(seq 1 500); do
		args=( "$(seq 1 "$j" | tr '\n' ' ' | sed 's/[[:space:]]*$//')" )
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test "quoted"
	done

	printf "\n"
}
