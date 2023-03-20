#! /bin/bash

for testpath in ../testcases/*.c; do 
    testcase=$(basename $testpath)
    echo $testcase
    ../iplC ../testcases/$testcase > ./output/$testcase.json 2> myout2.debug
    ../iplC_sany ../testcases/$testcase > ./output/sany_$testcase.json 2>/dev/null
    nl="$(cat ./output/$testcase.json | wc -l)"
    # echo $nl
    # exit 
    if [[ "$nl" -lt "3" ]]; then 
        diff -Bw ./output/$testcase.json ./output/sany_$testcase.json > ./diff/$testcase.diff 
        cat ./diff/$testcase.diff
    else 
        diff <(jq --sort-keys . "./output/$testcase.json") <(jq --sort-keys . "./output/sany_$testcase.json" ) > ./diff/$testcase.diff
        cat ./diff/$testcase.diff
    fi
done