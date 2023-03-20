#! /bin/bash

for testpath in ../testcases/*.c; do 
    testcase=$(basename $testpath)
    echo $testcase
    ../iplC ../testcases/$testcase > ./output/$testcase.json 2> myout2.debug
    ../iplC_sany ../testcases/$testcase > ./output/sany_$testcase.json 2>/dev/null 
    if [ $? -ne 0 ]; then 
        echo "Incorrect exit status" > ./diff/$testcase.diff 
    else 
        diff <(jq --sort-keys . "./output/$testcase.json") <(jq --sort-keys . "./output/sany_$testcase.json" ) > ./diff/$testcase.diff
        cat ./diff/$testcase.diff
    fi
done