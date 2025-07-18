lists_and_moves_only_bonus() {
    local TEST_NAME="Lists / 3 to 501"
    test_box "Lists : 3 to 501 (checker)"
    local LOCAL_TEST_NUMBER=0
    local MINI_COUNT=0

    SHOW_MINI_OK=true

    # On initialise PG_PARAMS (les paramètres généraux pour le test)
    PG_PARAMS=()
    PG_PARAMS+=("$CHECKER" 2 "mem" "err" "fail" '^OK$' '^$')

    local file="./aux/lists_and_moves.txt"
    local count=0
    local args_line=""
    local stdin_line=""

    while IFS= read -r line; do
        if (( count % 2 == 0 )); then
            # Ligne paire (0, 2, 4, ...): on considère que c'est la ligne d'arguments
            args_line="$line"
        else
            # Ligne impaire: c'est la ligne d'entrée.
            # Remplacer chaque espace par "\n"
			stdin_line=$(printf "%s" "$line" | tr ' ' '\n')
            # On peut alors appeler les tests.
            PG_ARGS=()
            PG_ARGS+=( "$args_line" )
            # On place PG_STDINS comme un tableau contenant la chaîne transformée.
            PG_STDINS=( "$stdin_line" )
			if (( count % 17 == 0 || count < 50 || (2 * count - 1) == 100 || (2 * count - 1) == 500 )); then
			    PG_PARAMS=()
   				PG_PARAMS+=("$CHECKER" 2 "mem" "err" "fail" '^OK$' '^$')
            	core_test "quoted"
			else
			    PG_PARAMS=()
    			PG_PARAMS+=("$CHECKER" 2 "null" "err" "fail" '^OK$' '^$')
				core_test "quoted"
			fi
        fi
        (( count++ ))
    done < "$file"

    printf "\n"
}
