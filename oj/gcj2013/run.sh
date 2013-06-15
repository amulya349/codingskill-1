#!/bin/sh
if [ $# -lt 1 ]; then
    echo "Usage: $0 tic-tac-toe-tomek"
    echo "       $0 treasure"
    #echo "       $0 dead_pixels"
    exit
fi

PROC=$1
SRC=${PROC}.cpp
TEST=${PROC}_test.txt
OUT=${PROC}_out.txt
if [ -f $SRC -a -f $TEST ]; then
    g++ ${SRC} -O2 -o ${PROC}
    if [ $? -eq 0 ]; then
        cat ${TEST} | ./${PROC} | tee ${OUT}
        rm -f $PROC
    fi
else
    echo "[$SRC] or [$TEST] is not exist"
fi
