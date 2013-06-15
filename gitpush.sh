#!/bin/sh

GITD=/home/weiguozhu/codingskill
if [ -d $GITD ] ; then
    start_time="`date`"
    cd $GITD
    rm -rf .git
    find . -name a.out | xargs rm -f
    find . -name core  | xargs rm -f
    git init
    git add .
    git commit -m "19981111"
#    git remote add origin https://ponyma@bitbucket.org/ponyma/codingskill.git
    git remote add origin https://ponyma@github.com/ponyma/codingskill.git
    git push -u origin --all 
    cd - 
    echo "[ ${start_time} ] - [ `date` ]"
else
    echo "[$GITD] not found."
fi
