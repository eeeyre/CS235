#!/bin/bash
EXE=dont_run_me

g++ -g -o$EXE Student_Code/*.cpp ignoreme.a
if (( $? )) ;
then 
	echo Compilation Failed;
else 
	chmod 755 $EXE;
	./$EXE; 
fi;
