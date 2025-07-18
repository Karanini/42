simple_lists_only()
{
	local TEST_NAME="Simple small lists"
	test_box "Simple small lists : 2 to 6 numbers (push_swap)"
	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

	local PLIST=()
	generate_permutations 2
	generate_permutations 3
	generate_permutations 4
	generate_permutations 5
	generate_permutations 6

	local NLIST=(1 2 3 4 8 9 10 32 33 34 152 153 154 872)

	SHOW_MINI_OK=true

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "mem" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	local num=1
	for args in "${PLIST[@]}"; do
    	if number_in_list "$num" "${NLIST[@]}"; then
			PG_ARGS=()
			PG_ARGS+=("$args")
			PG_ARGS+=("$args")
			core_test "quoted"
			core_test
		fi
		num=$((num + 1))
	done

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	local num=1
	for args in "${PLIST[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test
		num=$((num + 1))
	done

	local num=1
	for args in "${PLIST[@]}"; do
    	if number_in_list "$num" "${NLIST[@]}"; then
			PG_ARGS=()
			PG_ARGS+=("$args")
			PG_ARGS+=("$args")
			core_test "quoted"
		fi
		num=$((num + 1))
	done

	printf "\n"
	
}
