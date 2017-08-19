#!/bin/sh

make

//change your way to project corewar
TST_VAL="/nfs/2016/n/nyatsulk/projects/corewar/04_08_2017"
TST_WORK="/nfs/2016/n/nyatsulk/projects/corewar/04_08_2017/test_file"

COL="\033[;35m";
COL2="\033[;91m";
ESC="\033[33;0m";

echo "${COL}WRONG__1${ESC}"
echo "${COL2}no champs${ESC}"
./corewar -d 123
echo ""

echo "${COL}WRONG__2${ESC}"
echo "${COL2} not enough args${ESC}"
./corewar -n
echo ""

echo "${COL}WRONG__3${ESC}"
echo "${COL2} not enough args 2${ESC}"
./corewar -n 1 $TST_VAL/champs/examples/bee_gees.cor -n 2
echo ""

echo "${COL}WRONG__4${ESC}"
echo "${COL2}bad order of numb after flag -n${ESC}"
./corewar -n 4 $TST_VAL/champs/examples/bee_gees.cor
echo

echo "${COL}WRONG__5${ESC}"
echo "${COL2} wrong input file${ESC}"
./corewar $TST_VAL/champs/examples/bee_gees.s
echo ""

echo "${COL}WRONG__6${ESC}"
echo "${COL2} bad magic${ESC}"
./corewar $TST_WORK/bad_magic.cor
echo ""

echo "${COL}WRONG__7${ESC}"
echo "${COL2} prog size mismatch${ESC}"
./corewar $TST_WORK/bad_prog_size.cor
echo ""

echo "${COL}WRONG__8${ESC}"
echo "${COL2} big op ${ESC}"
./corewar $TST_WORK/big_op.cor
echo ""

echo "${COL}WRONG__9${ESC}"
echo "${COL2} small op${ESC}"
./corewar $TST_WORK/small_op.cor
echo ""

echo "${COL}WRONG__10${ESC}"
echo "${COL2}To many champions ${ESC}"
./corewar $TST_VAL/champs/examples/bee_gees.cor $TST_VAL/champs/examples/bee_gees.cor $TST_VAL/champs/examples/bee_gees.cor $TST_VAL/champs/examples/bee_gees.cor $TST_VAL/champs/examples/bee_gees.cor
echo ""

echo "${COL}WRONG__11${ESC}"
echo "${COL2} Bad numb in input line${ESC}"
./corewar -n -2 $TST_VAL/champs/examples/bee_gees.cor
echo ""

echo "${COL}WRONG__12${ESC}"
echo "${COL2} no numb after -d${ESC}"
./corewar -d -n
echo ""

echo "${COL}WRONG__13${ESC}"
echo "${COL2}${ESC}"

echo ""

echo "${COL}WRONG__14${ESC}"
echo "${COL2}${ESC}"

echo ""




