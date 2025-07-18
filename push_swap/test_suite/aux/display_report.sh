show_report_message() {

	IS_MEGA_TEST="$1"
	WITH_PERFS="$2"

	printf "\n"
	if [ "$MEGA_TEST" = true ]; then

		########### TEST GLOBAL ###########

		if [ "$WITH_PERFS" = true ]; then
			if (( NB_ERRORS == 0 )); then
				if (( NB_PERF_ERRORS == 0 )); then
					if (( NB_PERF_WARNINGS == 0 )); then
						# Super test réussi, performance géniales 
						create_box "\n🎉  ${BLD}${BRGN_B}Congratulations, all tests passed (${TEST_NUMBER}).  🥳\n \n🏅🏅🏅\n ${RST}" ${BRCN_B} 5;
					else
						# Super test réussi, mais performances moyennes
						create_box "\n${BLD}${BRGN_B}🥳  Congratulations, all tests passed (${TEST_NUMBER}).\n \nHowever, you can improve performance. 🧐\n ${RST}" ${BRCN_B} 5;
					fi
				else
					# Super test réussi, mais perfs non conformes
					create_box "\n${BLD}${BRGN_B}All tests passed (${TEST_NUMBER})  🤔,\n \nbut what a pity, the performance is beyond acceptable limits. 🧐\n ${RST}" ${BRYL_B} 2;
				fi	
			else
				# Super test raté, performances invalidées
				if [ "$NB_ERRORS" -gt "$TEST_NUMBER" ]; then
					create_box "\n${BLD}${BRYL_B}🤯🤯🤯🤯🤯\n \nCrazy amount of errors detected (${NB_ERRORS}).\n ${RST}" ${BRRD_B} 2;
				else
					create_box "\n${BLD}${BRYL_B}🤕  Warning : ${NB_ERRORS} errors detected.  🤯\n ${RST}" ${BRRD_B} 2;
				fi
			fi
		else
			if (( NB_ERRORS == 0 )); then
				# Super test réussi
				create_box "\n🎉  ${BLD}${BRGN_B}Congratulations, all tests passed (${TEST_NUMBER}).  🥳\n \n🏅🏅🏅\n ${RST}" ${BRCN_B} 5;
			else
				# Super test raté
				if (( NB_ERRORS == 1 )); then
					# Raté qvec une seule erreur !!!!!
					create_box "\n${BLD}${BRYL_B}😱  Warning : 1 error detected.  🙀\n \n💥 💥 💥\n ${RST}" ${BRYL_B} 2;
				else
					# Simplement raté
					if [ "$NB_ERRORS" -gt "$TEST_NUMBER" ]; then
						create_box "\n${BLD}${BRYL_B}🤯🤯🤯🤯🤯\n \nCrazy amount of errors detected (${NB_ERRORS}).\n ${RST}" ${BRRD_B} 2;
					else
						create_box "\n${BLD}${BRYL_B}💥  Warning : ${NB_ERRORS} errors detected.  🤯\n ${RST}" ${BRRD_B} 2;
					fi
				fi
			fi
		fi
	else
		########### TEST LOCAL ###########

		if [ "$WITH_PERFS" = true ]; then
			if (( NB_ERRORS == 0 )); then
				if (( NB_PERF_ERRORS == 0 )); then
					if (( NB_PERF_WARNINGS == 0 )); then
						# Test local réussi, performance géniales
						create_box "\n${BLD}${BRGN_B}Congratulations, ${TEST_NUMBER} tests passed.  🥳\n ${RST}" ${BRCN_B} 5;
					else
						# Test local réussi, mais performances moyennes
						create_box "\n${BLD}${BRGN_B}🥳  Congratulations, all tests passed (${TEST_NUMBER}).\n \nHowever, you can improve performance. 🧐\n ${RST}" ${BRCN_B} 5;
					fi
				else
					# Test local réussi, mais perfs non conformes
					create_box "\n${BLD}${BRGN_B}All tests passed (${TEST_NUMBER})  🤔,\n \nbut what a pity, the performance is beyond acceptable limits. 🧐\n ${RST}" ${BRYL_B} 2;
				fi	
			else
				# Test local raté, perfs invalidées
				if [ "$NB_ERRORS" -gt "$TEST_NUMBER" ]; then
					create_box "\n${BLD}${BRYL_B}🤯🤯🤯🤯🤯\n \nCrazy amount of errors detected (${NB_ERRORS}).\n ${RST}" ${BRRD_B} 2;
				else
					create_box "\n${BLD}${BRYL_B}🤕  Warning : ${NB_ERRORS} errors detected.  🤯\n ${RST}" ${BRRD_B} 2;
				fi
			fi

		else
			if (( NB_ERRORS == 0 )); then
				# Test local réussi
				create_box "\n${BLD}${BRGN_B}Congratulations, ${TEST_NUMBER} tests passed.  🥳\n ${RST}" ${BRCN_B} 5;
			else
				# Test local raté
				if (( NB_ERRORS == 1 )); then
					# Raté qvec une seule erreur !!!!!
					create_box "\n${BLD}${BRYL_B}😱  Warning : 1 error detected.  🙀\n \n💥 💥 💥\n ${RST}" ${BRYL_B} 2;
				else
					# Simplement raté
					if [ "$NB_ERRORS" -gt "$TEST_NUMBER" ]; then
						create_box "\n${BLD}${BRYL_B}🤯🤯🤯🤯🤯\n \nCrazy amount of errors detected (${NB_ERRORS}).\n ${RST}" ${BRRD_B} 2;
					else
						create_box "\n${BLD}${BRYL_B}💥  Warning : ${NB_ERRORS} errors detected.  🤯\n ${RST}" ${BRRD_B} 2;
					fi
				fi
			fi
		fi
	fi
	printf "\n"

	if (( NB_ERRORS > 0  || NB_PERF_ERRORS > 0 )); then
		printf "\n"
		printf "\n"
		display_text "Detailed error report available in traces files."
	fi

	printf "\n"
	display_text "Press any key to continue."
	printf "\n"
	read -r -n1 choice
}
