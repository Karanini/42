#!/bin/bash

DISPWIDTH=80
PADDING=3

PUSH_SWAP=""
CHECKER=""
CHECKER_L=""

source ./aux/utils.sh

source ./aux/files.sh
source ./aux/args.sh
source ./aux/colors.sh
source ./aux/permutations.sh
source ./aux/sequences.sh
source ./aux/display.sh
source ./aux/display_report.sh
source ./aux/report.sh

source ./aux/trace_fail.sh
source ./aux/trace_perf.sh
source ./aux/trace_prog.sh

source ./aux/test_prog_err.sh
source ./aux/test_core.sh

source ./aux/menu.sh

source ./aux/tests____basic_mem.sh
source ./aux/tests____basic.sh
source ./aux/tests____big_nums.sh
source ./aux/tests____limits_100.sh
source ./aux/tests____limits_500.sh
source ./aux/tests____limits_small.sh
source ./aux/tests____ordered_lists.sh
source ./aux/tests____random_lists.sh
source ./aux/tests____simple_lists.sh

source ./aux/tests_b__lists.sh
source ./aux/tests_b__basic_mem.sh
source ./aux/tests_b__basic.sh

find_push_swap

if [ -f "$PUSH_SWAP" ]; then
	printf "Executable found at: $PUSH_SWAP\n"
else
	create_box "${RD_B}ERROR: push_swap executable not found.${RST}" ${RD_B} 3;
	exit 1
fi

set_vars() {

	rm -f traces.txt
	rm -f traces_ok.txt
	rm -f traces_perf.txt

	find_push_swap

	TRACES=""
	PERF_TRACES=""

	TEST_NUMBER=0
	NB_PERF_ERRORS=0
	NB_PERF_WARNINGS=0
	NB_ERRORS=0

	FAILED_TESTS=()
	VALGRIND_TESTS=()
	TIMEOUT_TESTS=()
	ABORT_TESTS=()
	SEGFAULTS_TESTS=()

	BEYOND_LIMITS=()
	WARNING_LIMITS=()
	
}

debug() {
	set_vars
	big_num_lists_only
	errors_report false false
	menu
}

full_tests_no_bonus() {
	set_vars
	basic_tests_only
	basic_mem_tests_only
	simple_lists_only
	ordered_num_lists_only
	big_num_lists_only
	random_lists_only
	small_limits_tests_only
	limits_100_tests_only
	limits_500_tests_only
	errors_report true true
	menu
}

full_tests_bonus() {
	set_vars
	basic_tests_only_bonus
	basic_mem_tests_only_bonus
	lists_and_moves_only_bonus
	errors_report true true
	menu
}

stage_1() {
	set_vars
	basic_tests_only
	basic_mem_tests_only
	errors_report false false
	menu
}

stage_2() {
	set_vars
	simple_lists_only
	big_num_lists_only
	errors_report false false
	menu
}

stage_3() {
	set_vars
	ordered_num_lists_only
	random_lists_only
	errors_report false false
	menu
}

stage_4() {
	set_vars
	small_limits_tests_only
	limits_100_tests_only
	limits_500_tests_only
	errors_report false true
	menu	
}

stage_1_bonus() {
	set_vars
	basic_tests_only_bonus
	basic_mem_tests_only_bonus
	errors_report false false
	menu
}

stage_2_bonus() {
	set_vars
	lists_and_moves_only_bonus
	errors_report false false
	menu
}


menu


exit 0

