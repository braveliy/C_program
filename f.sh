#!/bin/bash

filename=$(ls | cat);

i=1;
while((1==1))  
do  
	split=$(echo $filename | cut -d " " -f $i);
	if [ "$split" != "" ]
	then
		((i++));
		result=$(cat "$split" | grep "$1");
		if [ "$result" != "" ]
		then
			echo $split;
			echo $result;
		fi
	else
		break;
	fi
done
