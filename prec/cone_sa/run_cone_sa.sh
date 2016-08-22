#!/bin/bash

set -e

SC=$CORVETTE_PATH/scripts

$SC/clean.sh .
rm -f final_inputs1 final_inputs2 spec.cov *.bc

$SC/compile.sh cone_sa_input .
lli cone_sa_input.bc


run=0
echo "No configuration is found!" > prec_output.txt
while [ "$(grep -c 'No configuration is found!' prec_output.txt)" -ge 1 ]; do
    $SC/compile.sh cone_sa .
    $SC/search.sh cone_sa .
    $SC/pconfig.sh cone_sa .

    $SC/dd2.py cone_sa.bc search_cone_sa.json config_cone_sa.json | tee  prec_output.txt
    sleep 2
    let run=run+1
done

echo "Prec runs used: " $run