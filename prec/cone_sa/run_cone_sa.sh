#!/bin/bash

set -e

SC=$CORVETTE_PATH/scripts

$SC/clean.sh .
rm -f final_inputs1 final_inputs2 spec.cov *.bc

$SC/compile.sh cone_sa_input .
lli cone_sa_input.bc

$SC/compile.sh cone_sa .

run=0
echo "No configuration_found!" > prec_output.txt
until [ $(grep -q "No configuration is found!" prec_output.txt) -eq 0 ]; do
    $SC/search.sh cone_sa .
    $SC/pconfig.sh cone_sa .

    $SC/dd2.py cone_sa.bc search_cone_sa.json config_cone_sa.json | tee  prec_output.txt
    sleep 2
    let run=run+1
done

echo "Prec runs used: " $run