find_in_parents() {
	local exe_name="$1"
	local dir="$2"
	while [ "$dir" != "/" ]; do
		if [ -f "$dir/$exe_name" ]; then
			echo "$dir/$exe_name"
			return 0
		fi
		dir=$(dirname "$dir")
	done
	return 1
}

find_dir_in_parents() {
	local target_dir="push_swap"
	local current_dir="$1"

	# Vérifier d'abord si le dossier "push_swap" existe dans le dossier donné en argument
	if [ -d "$current_dir/$target_dir" ]; then
		echo "$current_dir/$target_dir"
		return 0
	fi

	# Remonter la hiérarchie et, pour chaque dossier parent, vérifier si un dossier "push_swap" y est présent en tant que frère
	while [ "$current_dir" != "/" ]; do
		local parent_dir
		parent_dir=$(dirname "$current_dir")
		if [ -d "$parent_dir/$target_dir" ]; then
			echo "$parent_dir/$target_dir"
			return 0
		fi
		current_dir="$parent_dir"
	done

	return 1
}


find_push_swap() {
	# Recherche du fichier push_swap

	# D'abord, on tente de trouver un dossier "push_swap" parmi les parents
	dir_push_swap=$(find_dir_in_parents "$(pwd)")

	if [ -n "$dir_push_swap" ]; then
		# Si le dossier est trouvé, on privilégie le fichier push_swap qu'il contient
		if [ -x "$dir_push_swap/push_swap" ]; then
			PUSH_SWAP="$dir_push_swap/push_swap"
		fi
	fi

	# Si push_swap n'a pas été trouvé via le dossier, on cherche directement le fichier dans la hiérarchie
	if [ -z "$PUSH_SWAP" ]; then
		PUSH_SWAP=$(find_in_parents "push_swap" "$(pwd)")
	fi

	# Recherche de checker
	if [ -n "$PUSH_SWAP" ]; then
		# Si push_swap a été trouvé, on regarde s'il existe un exécutable checker dans le même répertoire
		dir_of_push_swap=$(dirname "$PUSH_SWAP")
		if [ -x "$dir_of_push_swap/checker" ]; then
			CHECKER="$dir_of_push_swap/checker"
		else
			CHECKER=""
		fi
	else
		# Si push_swap n'est pas trouvé, on cherche désespérément checker dans la hiérarchie
		CHECKER=$(find_in_parents "checker" "$(pwd)")
	fi

	# PUSH_SWAP=$(find_in_parents "push_swap" $(pwd))
	# CHECKER=$(find_in_parents "checker" $(pwd))
	CHECKER_L=$(find_in_parents "checker_linux" "./aux")
}


show_files() {
	find_push_swap
	clear
	create_box "\n ${BRCN_B}Executable locations\n ${RST}" ${BRMG_B} 5


	printf "\n\n - push_swap directory\n\n"

	if [ -n "$dir_push_swap" ]; then
		printf "    ✅ ${BRBL_B}$dir_push_swap${RST}"
	else
		printf "    ❌ ${BRRD_B}Not found${RST}"
	fi
	printf "\n\n\n\n"	



	printf " - push_swap\n\n"

	if [ -n "$PUSH_SWAP" ]; then
		printf "    ✅ ${BRGN_B}Found${RST}"
	else
		printf "    ❌ ${BRRD_B}Not found${RST}"
	fi
	printf "\n\n\n\n"


	printf " - checker\n\n"

	if [ -n "$CHECKER" ]; then
		printf "    ✅ ${BRGN_B}Found${RST}"
	else
		printf "    ❌ ${BRRD_B}Not found${RST}"
	fi
	printf "\n\n\n\n"


	printf " - checker_linux\n\n"

	if [ -n "$CHECKER_L" ]; then
		printf "    ✅ ${BRBL_B}$CHECKER_L${RST}"
	else
		printf "    ❌ ${BRRD_B}Not found${RST}"
	fi

	printf "\n\n"
}

