MAX_RAND=2147483647

seeded_random_source() {
	# awk -v seed="$1" -v max="$MAX_RAND" 'BEGIN {
	# 	srand(seed);
	# 	while (1)
	# 		printf("%d\n", int(rand()*max));
	# }'
	perl -e 'my $seed = shift; srand($seed); while (1) { print pack("C", int(rand(256))); }' "$1" 2>/dev/null

}

next_seed() {
	# Générateur congruentiel linéaire simple pour obtenir un nouveau seed, modulo MAX_RAND
	echo $(( ("$1" * 110351 + 3) % MAX_RAND ))
}

generate_sequence() {
	local a="$2"
	local b="$3"
	seq "$a" "$b" | shuf --random-source=<(seeded_random_source "$1") \
		| tr '\n' ' ' \
		| sed 's/[[:space:]]*$//'
}

generate_sequences() {
	# Génère une série de permutations déterministes à partir d'une graine initiale
	local nb_perms="$1"
	local start="$2"
	local end="$3"
	local seed="$4"

	local i

	for i in $(seq 1 "$nb_perms"); do
		perm=$(generate_sequence "$seed" "$start" "$end")
		SEQUENCES+=( "$perm" )
		seed=$(next_seed "$seed")	
	done
}

exemple_seed() {
	local SEQUENCES=()
	generate_sequences 4 -2147483648 $(( -2147483649 + 2 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 5 )) 42
	generate_sequences 4 -2147483648 $(( -2147483649 + 50 )) 42
	for PROG_ARGS in "${SEQUENCES[@]}"; do
		printf "%b" "$PROG_ARGS"
	done
}


