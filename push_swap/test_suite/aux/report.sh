errors_report() {
	
	local GLOBAL_ERROR_MESSAGE=""

	if [ ${#ABORT_TESTS[@]} -ne 0 ]; then
		GLOBAL_ERROR_MESSAGE+=$'\n'"${RD_B}Abort Tests:${RST}"$'\\n'
		for abort_el in "${ABORT_TESTS[@]}"; do
			GLOBAL_ERROR_MESSAGE+="${abort_el}"
		done
	fi

	if [ ${#SEGFAULTS_TESTS[@]} -ne 0 ]; then
		GLOBAL_ERROR_MESSAGE+=$'\n'"${RD_B}Segfaults Tests:${RST}"$'\\n'
		for seg in "${SEGFAULTS_TESTS[@]}"; do
			GLOBAL_ERROR_MESSAGE+="${seg}"
		done
	fi

	if [ ${#VALGRIND_TESTS[@]} -ne 0 ]; then
		GLOBAL_ERROR_MESSAGE+=$'\n'"${RD_B}Memory Leak Tests:${RST}"$'\\n'
		for leak in "${VALGRIND_TESTS[@]}"; do
			GLOBAL_ERROR_MESSAGE+="${leak}"
		done
	fi

	if [ ${#FAILED_TESTS[@]} -ne 0 ]; then
		GLOBAL_ERROR_MESSAGE+=$'\n\n'"${RD_B}Failed Tests:${RST}"$'\n\n'
		for failed in "${FAILED_TESTS[@]}"; do
			GLOBAL_ERROR_MESSAGE+="${failed}"
		done
	fi

	if [ ${#TIMEOUT_TESTS[@]} -ne 0 ]; then
		GLOBAL_ERROR_MESSAGE+=$'\n'"${RD_B}Timeout Tests:${RST}"$'\n\n'
		for timeout in "${TIMEOUT_TESTS[@]}"; do
			GLOBAL_ERROR_MESSAGE+="${timeout}"
		done
	fi

	

	show_report_message "$1" "$2"
}