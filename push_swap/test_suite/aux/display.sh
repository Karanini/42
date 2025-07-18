repeat_char() {
	local count=$1
	local char="$2"
	local i
	for (( i=0; i<count; i++ )); do
		printf "%b" "$char"
	done
}

display_text() {
	local text="$1"
	local TWIDTH=$(tput cols)
	[ "$TWIDTH" -gt "$DISPWIDTH" ] && TWIDTH=$DISPWIDTH
	TWIDTH=$(( TWIDTH - 2 * $PADDING ))
	wrap_text "$text" $(( $TWIDTH - 4 ))

	for line in "${WRAPPED_TEXT[@]}"; do
		repeat_char $(( PADDING )) ' '
		printf "%b" "$line"
	done
}

create_box() {
	local TWIDTH=$(tput cols)
	[ "$TWIDTH" -gt "$DISPWIDTH" ] && TWIDTH=$DISPWIDTH
	TWIDTH=$(( TWIDTH - 2 * $PADDING ))
	local text="$1"
	local bordercolor="$2"
	local model="$3"
	local hz; local vt
	local tl; local tr
	local bl ;local br

	if [ "$model" -eq "1" ]; then
		hz='-'; vt='|'; tl='+'; tr='+'; br='+'; bl='+'
	elif [ "$model" -eq "2" ]; then
		hz='*'; vt='*'; tl='*'; tr='*'; bl='*'; br='*'
	elif [ "$model" -eq "3" ]; then
		hz='#'; vt='#'; tl='#'; tr='#'; bl='#'; br='#'
	elif [ "$model" -eq "4" ]; then
		hz='═'; vt='║'; tl='╔'; tr='╗'; bl='╚'; br='╝'
	elif [ "$model" -eq "5" ]; then
		hz='='; vt='|'; tl='o'; tr='o'; bl='o'; br='o'
	fi

	repeat_char $(( PADDING )) ' '
	create_line "$tl" "$hz" "$tr" "$bordercolor"

	wrap_text "$text" $(( $TWIDTH - 4 ))  # Largeur totale moins 2 pour garder les bords

	for line in "${WRAPPED_TEXT[@]}"; do
		#if [ -n "$line" ]; then  # Évite d'afficher une ligne vide
			repeat_char $(( PADDING )) ' '
			create_cline "$vt" "$line" "$bordercolor"
		#fi
	done
	repeat_char $(( PADDING)) ' '
	create_line "$bl" "$hz" "$br" "$bordercolor"
}

create_line() {
	local left="$1"
	local char="$2"
	local right="$3"
	local color="$4"
	printf "${color}${left}$(repeat_char "$(( $TWIDTH ))" "$char")${right}${RST}\n"
}

calculate_width() {
	local input="$1"
	local total=0
	# Convertir la chaîne en UTF-32LE pour obtenir les codepoints sous forme hexa
	local hex_codes
	hex_codes=$(printf "%s" "$input" | iconv -f UTF-8 -t UTF-32LE | od -An -t x4 | tr -s ' ' | sed 's/^ //')
	local cp_dec
	for cp in $hex_codes; do
		cp_dec=$((16#$cp))
		# Utiliser (( )) pour l'évaluation arithmétique qui supporte la notation hexa
		if (( cp_dec >= 0x1100 )); then
			total=$((total + 2))
		else
			total=$((total + 1))
		fi
	done
	printf "%d" "$total"
}

create_cline() {
	local vt="$1"
	local text="$2"
	local bordercolor="$3"
	# Supprimer les codes ANSI pour mesurer le texte « brut »
	local raw_text
	raw_text=$(echo -e "$text" | sed 's/\x1B\[[0-9;]*m//g')
	# Calculer la largeur affichée réelle (en colonnes)
	local text_length
	text_length=$(calculate_width "$raw_text")
	# Calculer le padding pour que le contenu (texte + padding) fasse TWIDTH-2 colonnes
	local total_padding=$(( TWIDTH - text_length ))
	local left_padding=$(( total_padding / 2 ))
	local right_padding=$(( total_padding - left_padding ))
	# Afficher la ligne avec le contenu centré et les bords
	printf "${bordercolor}$vt${RST}%*s%s%*s${bordercolor}$vt${RST}\n" "$left_padding" "" "$text" "$right_padding" ""
}


show_mini_res() {
	local symb="$1"
	local color="$2"
	local TWIDTH=$(tput cols)

	MINI_COUNT=$(( MINI_COUNT + 1 ))

	[ "$TWIDTH" -gt "$DISPWIDTH" ] && TWIDTH="$DISPWIDTH"
	TWIDTH=$(( TWIDTH - 2 * ${PADDING} - 4 ))

	if (( 10#$MINI_COUNT % TWIDTH == 1 )); then
		if (( 10#$MINI_COUNT > 1 )); then
			printf "\n"
		fi
		repeat_char $(( PADDING + 2 )) ' '
	fi
	printf "${color}${symb}${RST}"
}

test_box() {
	local TEXT="$1"
	printf "\n"
	create_box "${BLD}${BRBL_B}${TEXT}${RST}" ${BRBL_B} 1;
	printf "\n"
}

wrap_text() {
	local input_raw="$1"
	local width="$2"
	WRAPPED_TEXT=()

	# Convertir les séquences d'échappement (ex. \n) en retours à la ligne réels
	local text
	text=$(printf "%b" "$input_raw")

	# Lire le texte ligne par ligne (la condition || [ -n "$line" ] permet de capturer une dernière ligne vide)
	while IFS= read -r line || [ -n "$line" ]; do
		# Si la ligne est vide, on la remplace par un espace pour qu'elle soit prise en compte
		if [ -z "$line" ]; then
			line=" "
		fi
		# Découper la ligne en segments qui ne dépassent pas 'width' caractères
		while IFS= read -r segment; do
			# Retirer les espaces en fin de segment
			segment=$(echo "$segment" | sed 's/[[:space:]]*$//')
			# Si le segment est vide après nettoyage, le forcer à contenir un espace
			if [ -z "$segment" ]; then
				segment=" "
			fi
			WRAPPED_TEXT+=("$segment")
		done < <(echo "$line" | fold -s -w "$width")
	done <<< "$text"
}

wrap_text2() {
    local input_raw="$1"
    local width="$2"
    WRAPPED_TEXT=()

    # Conversion des séquences d'échappement en retours à la ligne réels
    local text
    text=$(printf "%b" "$input_raw")

    # Lecture ligne par ligne (la condition permet de capter une éventuelle dernière ligne vide)
    while IFS= read -r line || [ -n "$line" ]; do
        if [ -z "$line" ]; then
            WRAPPED_TEXT+=("")
        else
            # Découpage de la ligne en segments ne dépassant pas 'width' caractères
            while IFS= read -r segment; do
                segment=$(echo "$segment" | sed 's/[[:space:]]*$//')
                WRAPPED_TEXT+=("$segment")
            done < <(echo "$line" | fold -s -w "$width")
        fi
    done <<< "$text"
}

disp_wrapped_text() {
    wrap_text2 "$1" $(( $TWIDTH))  # Largeur totale moins 2 pour garder les bords
	for line in "${WRAPPED_TEXT[@]}"; do
		repeat_char $(( PADDING )) ' '
		printf "%b\n" "$line"
	done
}

show_informations() {
	local TWIDTH=$(tput cols)
	[ "$TWIDTH" -gt "$DISPWIDTH" ] && TWIDTH=$DISPWIDTH
	TWIDTH=$(( TWIDTH - 2 * $PADDING ))
    clear
	echo ""
	echo ""
    create_box "\n ${BRGN_B}[FR] Avertissement\n ${RST}" ${BRCN_B} 4

    # Version Française
	text="\n"
    text+="Lapinou42 (alias ProfChaos, alias DoctorDoom, et tant d'autres) n'est pas reponsable et ne rembourse pas si :\n"
    text+="- Le script ne fonctionne pas.\n"
	text+="- Quelque chose tourne mal.\n"
	text+="- Dans tous les autres cas.\n\n"
    text+="Par ailleurs, si votre répertoire /home et vos données ont été effacés ou l'ordinateur a commencé à brûler, sachez que Lapinou42 à déjà pris la poudre d'escampette et il ne sert à rien de lui courir après.\n"
    text+="\n"
    text+="Licence CC-BY-NC-SA\n "

	disp_wrapped_text "$text"

	printf "\n\n"


	create_box "\n ${BRGN_B}[EN] Disclaimer\n ${RST}" ${BRCN_B} 4


	# English Version
	text="\n"
	text+="Lapinou42 (also known as ProfChaos, DoctorDoom, and many others) is not responsible and does not refund if:\n"
	text+=" - The script does not work.\n"
	text+=" - Something goes wrong.\n"
	text+=" - In all other cases.\n\n"
	text+="Furthermore, if your /home directory and your data have been erased or if your computer started burning, know that Lapinou42 has already fled and there's no point in chasing after him.\n"
	text+="\n"
	text+="License CC-BY-NC-SA\n"

	disp_wrapped_text "$text"

}

