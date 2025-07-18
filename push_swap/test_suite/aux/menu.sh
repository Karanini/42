menu() {
	while true; do
		clear
		printf "\n"
		create_box "\n${GN_B}Push_swap Test Suite${RST}\n\n${MG_B}CREATED BY: ${BRCN_B}Lapinou42${RST}\n " ${GN_B} 4
		printf "\n"
		display_text "${BRBL_B}1) Full tests (push_swap only)${RST}"
		printf "\n"
		display_text "${BRBL_B}2) Full tests (bonus only)${RST}"
		printf "\n"
		display_text "${BRMG_B}3) Performance tests${RST}"
		printf "\n\n"
		display_text "A) Stage 1 : Basic args tests"
		printf "\n"
		display_text "B) Stage 2 : Easy tests (seq)"
		printf "\n"
		display_text "C) Stage 3 : Hard tests (seq)"
		printf "\n"
		display_text "D) Stage 4 : Limits tests"
		printf "\n\n"
		if [ -n "$CHECKER" ]; then
			display_text "E) Bonus stage 1 - Basic tests"
			printf "\n"
			display_text "F) Bonus stage 2 - List tests"
			printf "\n"
		fi
		display_text "G)"
		printf "\n\n"
		display_text "S) Show files paths"
		printf "\n"
		display_text "Z) More informations"
		printf "\n\n"
		display_text "Press 'q', 'Q' or ESC to exit"
		printf "\n\n"
		read -rsn1 key
		case "$key" in
			1) full_tests_no_bonus ;;
			2) if [ -n "$CHECKER" ]; then full_tests_bonus; else continue; fi ;;
			a|A) stage_1 ;;
			b|B) stage_2 ;;
			c|C) stage_3 ;;
			d|D) stage_4 ;;
			e|E) if [ -n "$CHECKER" ]; then stage_1_bonus; else continue; fi ;;
			f|F) if [ -n "$CHECKER" ]; then stage_2_bonus; else continue; fi ;;
			q|Q) exit 0 ;;
			s|S) show_files;;
			z|Z) show_informations;;
			h|H|5) debug;;
			$'\e') exit 0 ;;
			*) continue ;;
		esac
		printf "\n\n"
		read -rsn1 -p "Press any key to return to the menu..."
	done
}
