trace_fail() {
	local error_type="$1"
	local tools;
	local nbcheck=0;

	NB_ERRORS=$(( NB_ERRORS + 1 ))
	
	local formatted_args
	formatted_args=$(format_prog_args "${PROG_ARGS__[@]}")
	local stdout_line stderr_line

	if [[ "$pg_out_content" =~ $pg_out_expected ]]; then
		stdout_line="--------------------------------- stdout  [OK] --------------------------------"
	else
		stdout_line="--------------------------------- stdout  [KO] --------------------------------"
	fi

	if [[ "$pg_err_content" =~ $pg_err_expected ]]; then
		stderr_line="--------------------------------- stderr  [OK] --------------------------------"
	else
		stderr_line="--------------------------------- stderr  [KO] --------------------------------"
	fi

	if [[ "$mem_test" = "mem" ]]; then
		tools="Valgrind"
		nbcheck=1
	fi

	if [[ "$err_test" = "err" ]]; then
		if [ "$nbcheck" -eq 1 ]; then
			nbcheck=2
			tools+=" / "
		else
			nbcheck=1
		fi
		tools+="System"
	fi

	if [ "$nbcheck" -eq 0 ]; then
		tools+="None"
	fi


	cat <<EOF >> traces.txt

o================================== Test ${TEST_ID} ==================================
| Program : $(basename "$prog")      @@@@@@[ $error_type ]@@@@@@
| Test name : $TEST_NAME 
| Exit code : $pg_exit_code
| MCheck : ${tools}
|-------------------------------------------------------------------------------
| Args : ${formatted_args}$( [ -n "$PG_STDINS" ] && printf "\n%s" "| Stdin : $(format_prog_args "${PG_STDINS}")")
|${stdout_line}
| expected : |${pg_out_expected}|
| result   : |${pg_out_content}|
|${stderr_line}
| expected : |${pg_err_expected}|
| result   : |${pg_err_content}|
o===============================================================================


EOF
}
