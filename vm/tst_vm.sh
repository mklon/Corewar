#!/bin/sh

make

TST_VAL="/nfs/2016/n/nyatsulk/projects/corewar/04_08_2017"
TST_WORK=

COL="\033[;35m";
COL2="\033[;91m";
ESC="\033[33;0m";

echo "${COL}WRONG${ESC}"
echo "${COL2}no champs${ESC}"
./corewar -d 123
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} not enough args${ESC}"
./corewar -n
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2}bad order of numb after flag -n${ESC}"
./corewar -n 4 $TST_VAL/../champs/examples/bee_gees.cor
echo

echo "${COL}WRONG${ESC}"
echo "${COL2} wrong input file${ESC}"
./corewar $TST_VAL/../champs/examples/bee_gees.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} bad magic${ESC}"
./corewar $TST_VAL/bad_magic.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} prog size mismatch${ESC}"
./corewar $TST_VAL/bad_prog_size.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} big op ${ESC}"
./corewar $TST_VAL/big_op.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} small op${ESC}"
./corewar $TST_VAL/small_op.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2}To many champions ${ESC}"
./corewar $TST_VAL/../champs/examples/bee_gees.cor $TST_VAL/../champs/examples/bee_gees.cor $TST_VAL/../champs/examples/bee_gees.cor $TST_VAL/../champs/examples/bee_gees.cor $TST_VAL/../champs/examples/bee_gees.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} Bad numb in input line${ESC}"
./corewar -n -2 $TST_VAL/../champs/examples/bee_gees.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} Bad numb of players in input line${ESC}"
./corewar -n 4 $TST_VAL/../champs/examples/bee_gees.cor -n 2 $TST_VAL/../champs/examples/bee_gees.cor -n 1 $TST_VAL/../champs/examples/bee_gees.cor -n 3 $TST_VAL/../champs/examples/bee_gees.cor -n 5 $TST_VAL/../champs/examples/bee_gees.cor
echo ""

echo "${COL}WRONG${ESC}"
echo "${COL2} ${ESC}"

echo ""
