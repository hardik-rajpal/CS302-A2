#! /bin/sh
arr=$(ls ../testcases)

for f in $arr; do 
    ./iplC ../testcases/$f >myout2.txt 2>/dev/null
    ../iplC ../testcases/$f >sany2.txt 2>/dev/null
    (diff -Bw myout2.txt sany2.txt) > diff.txt
    echo "error messages for $f:"
    cat diff.txt
done