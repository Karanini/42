random_lists_only() {
	TEST_NAME="Pseudo random lists"
	test_box "Pseudo random lists : 2 to 500 nums (push_swap)"
	local LOCAL_TEST_NUMBER=0
	local MINI_COUNT=0

 	local SEQUENCES=()

	for j in $(seq 1 499); do
		generate_sequences 1 0 "$j" 42
	done

	SHOW_MINI_OK=true

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "mem" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	local i=0
	for args in "${SEQUENCES[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test
		if (( i % 25 == 0 )); then
			core_test "quoted"
		fi
		i=$(( i + 1 ))
	done

	PG_PARAMS=()
	PG_PARAMS+=("$PUSH_SWAP" 2 "null" "err" "fail" '.*' '^$')
	PG_PARAMS+=("$CHECKER_L" 5 "null" "null" "fail" '^OK$' '^$')

	local i=0
	for args in "${SEQUENCES[@]}"; do
		PG_ARGS=()
		PG_ARGS+=("$args")
		PG_ARGS+=("$args")
		core_test
		if (( i % 25 == 0 )); then
			core_test "quoted"
		fi
		i=$(( i + 1 ))
	done

	printf "\n"
}
