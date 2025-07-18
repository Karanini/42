
number_in_list() {
	local needle="$1"
	shift
	for item in "$@"; do
		if [ "$item" -eq "$needle" ]; then
			return 0
		fi
	done
	return 1
}

generate_permutations() {
	local n="$1"
	local i mobile mobile_index swap_index d current neighbor temp
	local perm=()
	declare -A dir
	for (( i=1; i<=n; i++ )); do
		perm+=("$i")
		dir["$i"]=-1
	done

	print_perm() {
		local out=""
		local first=1
		for x in "${perm[@]}"; do
			if [ $first -eq 1 ]; then
				out+="$x"
				first=0
			else
				out+=" $x"
			fi
		done
		PLIST+=( "$out" )
	}

	print_perm

	while true; do
		mobile=-1
		mobile_index=-1
		for (( i=0; i<n; i++ )); do
			current=${perm[i]}
			d=${dir["$current"]}
			neighbor_index=$(( i + d ))
			if (( neighbor_index < 0 || neighbor_index >= n )); then
				continue
			fi
			neighbor=${perm[neighbor_index]}
			if (( current > neighbor && current > mobile )); then
				mobile=$current
				mobile_index=$i
			fi
		done
		(( mobile == -1 )) && break
		swap_index=$(( mobile_index + ${dir["$mobile"]} ))
		temp=${perm[mobile_index]}
		perm[mobile_index]=${perm[swap_index]}
		perm[swap_index]=$temp
		print_perm
		for (( i=0; i<n; i++ )); do
			if (( perm[i] > mobile )); then
				dir["${perm[i]}"]=$(( - ${dir["${perm[i]}"]} ))
			fi
		done
	done
}
