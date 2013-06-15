#!/bin/sh
if [ $# -lt 1 ]; then
    echo "Usage: $0 beautiful_strings"
    echo "       $0 balanced_smileys"
    echo "       $0 find_the_min"
    exit
fi

PROC=$1
SRC=${PROC}.cpp
TEST=${PROC}_test.txt
if [ -f $SRC -a -f $TEST ]; then
    g++ -g ${SRC} -o ${PROC}
    if [ $? -eq 0 ]; then
        cat ${TEST} | ./${PROC}
        rm -f $PROC
    fi
else
    echo "[$SRC] or [$TEST] is not exist"
fi
