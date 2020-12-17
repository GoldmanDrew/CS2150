#!/bin/bash
read file1 file2  # takes in two files as parameters 
RUNNING_TIME=`./a.out ${file1} ${file2} | tail -1`
RUNNING_TIME2=`./a.out ${file1} ${file2} | tail -1`
RUNNING_TIME3=`./a.out ${file1} ${file2} | tail -1`
RUNNING_TIME4=`./a.out ${file1} ${file2} | tail -1`
RUNNING_TIME5=`./a.out ${file1} ${file2} | tail -1`
echo $(((RUNNING_TIME+RUNNING_TIME2+RUNNING_TIME3+RUNNING_TIME_4+RUNNING_TIME5)/5))


