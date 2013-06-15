#!/bin/sh
if [ $# -lt 1 ]; then
    echo "Usage: $0 card_game"
    echo "       $0 security"
    echo "       $0 dead_pixels"
    exit
fi

CARG=-pg
PROC=$1
SRC=${PROC}.cpp
TEST=${PROC}_test.txt
if [ -f $SRC -a -f $TEST ]; then
    g++ ${CARG} ${SRC} -o ${PROC}
    if [ $? -eq 0 ]; then
        cat ${TEST} | ./${PROC}
        rm -f $PROC
    fi
else
    echo "[$SRC] or [$TEST] is not exist"
fi
