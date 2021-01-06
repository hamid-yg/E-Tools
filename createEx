#!/bin/bash

if [ ! $1 ]
then
    echo "nothing"
else
    for i in `seq 1 $1`;
        do
            if [ -d ex_0$1 ]
            then
                continue
            else
                if [ $i -lt 10 ]
                then
                    touch ex_0$i
                else
                    touch ex_$i
                fi
            fi
    done
fi