trace_perf() {
	local score="$1"
	local moves="$2"
	local list="$3"
	local id="$TEST_ID"

	if [[ $score -eq 0 ]]; then
		NB_PERF_ERRORS=$(( NB_PERF_ERRORS + 1 ))
	else
		NB_PERF_WARNINGS=$(( NB_PERF_WARNINGS + 1 ))
	fi

	cat <<EOF >> traces_perf.txt

o================================== Test ${TEST_ID} ==================================
| Program : $(basename "$prog") : @@@@@@[ Perf. alert ${moves} ]@@@@@@
| Test name : ${TEST_NAME}
| Score : ${score}
| Moves : ${count}
|-------------------------------------------------------------------------------
| List : ${list}
o===============================================================================


EOF
}
