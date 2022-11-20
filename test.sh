#!/bin/bash
# flag=0
# for ((var = 1 ; $var <= 5; var++))
# do
#     FILENAME='data/Integer1/'$var
#     cp $FILENAME.cpp src/main.cpp
#     bash build.sh > test.log
#     startTime=`date +"%s.%N"`
#     ./bin/bigint < $FILENAME.in > test.out
#     endTime=`date +"%s.%N"` 
#     DIFF=$(diff test.out $FILENAME.out)
#     if ["$DIFF" == ""]
#     then
#         echo "Answer correct on testdata Integer 1/"$var"."
#     else
#         flag=1
#     fi
#     echo `awk -v x1="$(echo $endTime | cut -d '.' -f 1)" -v x2="$(echo $startTime | cut -d '.' -f 1)" -v y1="$[$(echo $endTime | cut -d '.' -f 2) / 1000]" -v y2="$[$(echo $startTime | cut -d '.' -f 2) /1000]" 'BEGIN{printf "RunTime:%.6f s",(x1-x2)+(y1-y2)/1000000}'`
# done
# if [ $flag == 1 ]
# then
#     echo "Failed test on Integer 1"
# else
#     echo "Succeed on Integer 1"
# fi
flag=0
for ((var = 1 ; $var <= 18; var++))
do
    FILENAME='data/Integer2/'$var
    cp $FILENAME.cpp src/main.cpp
    bash build.sh > test.log
    startTime=`date +"%s.%N"`
    ./bin/bigint < $FILENAME.in > test.out
    endTime=`date +"%s.%N"` 
    DIFF=$(diff test.out $FILENAME.out)
    if ["$DIFF" == ""]
    then
        echo "Answer correct on testdata Integer 2/"$var"."
    else
        flag=1
    fi
    echo `awk -v x1="$(echo $endTime | cut -d '.' -f 1)" -v x2="$(echo $startTime | cut -d '.' -f 1)" -v y1="$[$(echo $endTime | cut -d '.' -f 2) / 1000]" -v y2="$[$(echo $startTime | cut -d '.' -f 2) /1000]" 'BEGIN{printf "RunTime:%.6f s",(x1-x2)+(y1-y2)/1000000}'`
done
if [ $flag == 1 ]
then
    echo "Failed test on Integer 2"
else
    echo "Succeed on Integer 2"
fi