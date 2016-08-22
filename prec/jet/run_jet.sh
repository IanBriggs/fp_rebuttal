#!/bin/bash

set -e

SC=$CORVETTE_PATH/scripts

$SC/clean.sh .
rm -f final_inputs1 final_inputs2 spec.cov *.bc

$SC/compile.sh jet_input .
lli jet_input.bc

$SC/compile.sh jet .
$SC/search.sh jet .
$SC/pconfig.sh jet .

$SC/dd2.py jet.bc search_jet.json config_jet.json