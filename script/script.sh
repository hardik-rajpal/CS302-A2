#! /usr/bin/env bash
arr=$(ls ../testcases)
echo running testcases > diff.txt
for f in $arr; do 
    ../iplC ../testcases/$f >myout2.json 2>/dev/null
    ../iplC_sany ../testcases/$f >sany2.json 2>/dev/null
    echo "error messages for $f:"
    if [[ $(wc -l myout2.json) -lt 3 ]]
    then 
        if [[ $(wc -l sany2.json) -lt 3 ]] 
        then
            echo "error but everything is cool"
        else 
            echo "error and you're fucked"
        fi
    else 
        diff <(jq --sort-keys . myout2.json) <(jq --sort-keys . sany2.json)
    fi
done