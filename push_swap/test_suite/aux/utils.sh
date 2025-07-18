escape_non_printable() {
	local input="$1"
	local result=""
	local i char code
	for (( i=0; i < ${#input}; i++ )); do
		char="${input:$i:1}"
		if [ "$char" = $'\n' ]; then
			result+="\\n"
		elif [ "$char" = $'\t' ]; then
			result+="\\t"
		elif [ "$char" = $'\r' ]; then
			result+="\\r"
		elif [ "$char" = $'\a' ]; then
			result+="\\a"
		elif [ "$char" = $'\b' ]; then
			result+="\\b"
		elif [ "$char" = $'\e' ]; then
			result+="\\e"
		elif [ "$char" = $'\f' ]; then
			result+="\\f"
		elif [ "$char" = $'\v' ]; then
			result+="\\v"
		elif [ "$char" = $'\\' ]; then
			result+="\\\\"
		elif [ "$char" = "'" ]; then
			result+="\\'"
		elif [ "$char" = "\"" ]; then
			result+="\\\""
		else
			printf -v code "%d" "'$char"
			if [ "$code" -ge 32 ] && [ "$code" -le 126 ]; then
				result+="$char"
			else
				result+=$(printf '\\x%02x' "$code")
			fi
		fi
	done
	printf "%s" "$result"
}

format_prog_args() {
	local formatted=""
	local elem escaped
	local prefix="\$'"  # Affiche littéralement $'
	local suffix="'"
	# Traiter tous les arguments passés
	for elem in "$@"; do
		escaped=$(escape_non_printable "$elem")
		formatted+="${prefix}${escaped}${suffix} "
	done
	# Supprime le dernier espace
	printf "%s" "${formatted% }"
}
