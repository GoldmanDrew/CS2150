#!/bin/bash
#Drew Goldman
#dag5wd
#10/21/20
#averagetime.sh

echo "enter the exponent for counter.cpp: "
read e

if [[ $e == "quit" ]] ; then
	exit 0    
fi

tot=0
n=5

for i in {1..5} ; do
    echo "Running iteration ${i}..."
    t=`./a.out ${e}`
    echo "time taken: ${t} ms"
    tot=`expr $t + $tot`
done

avg=`expr $tot / $n`

echo "${n} iterations took ${tot} ms"
echo "Average time was ${avg} ms"
