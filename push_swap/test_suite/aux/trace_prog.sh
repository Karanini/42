trace_ok() {
	local error_type="$1"
  
	# Supposons que PROG_ARGS__ est un tableau

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
  
	cat <<EOF >> traces_ok.txt

o================================== Test ${TEST_ID} ==================================
| Program : $(basename "$prog")
| Test name : ${TEST_NAME}
| Exit code : ${pg_exit_code}
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


