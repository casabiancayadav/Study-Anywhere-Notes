# Shell Scripting				

1. Shell Scipting is a programming language to automate.
2.  It execute commands sequentially just like python langauage.
3. First line must be 
   		#!/bin/sh
4.  Write commands as you are writting in linux terminal.



##  Input/Output commands :

```shell

	1# Output :
	===========
		> echo
			1@ : < $echo [options] > command is used to print output on terminal. i.e echo "Hello World !!!"
			2@ : [options]
					[$echo -n ] =>> By defualt echo command give output and put newline and start from new line.
									but this option [-n] disable this default behaviour.
									
					[@echo -e ] ==>> By default echo command give output as it is written between double quote.
									 it doesnot understand backslash escapes i.e \n, \t, \r etc.
									 But by using this option [-e] we enable it.
		> printf
			1@ : Printf works as it works as in C language.
			2@ : It has format specifier capabilty.
			3@ : i.e printf "kitne aadmi the kaaliya %d" "4"
			4@ : For new line we need to give '\n' in printf. Like C language.
		
	2# Input :
	==========
		> read
			1@ : Read command takes argurments from STDIN.
			2@ : i.e read varName
					 echo $varName
					 
			3@ : read command has default variable $REPLY which works of you don't  specify own variable.
					i.e read
						echo $REPLY

```

##  conditional commands :

​    1# if
​	2# if-else
​	3# if-else-if
​	4# switch-case
​	5# break
​	6# continue

​	

##   Loops :

1# for loop
2# while loop
3# Untill loop



## Funcation



## Miscellaneous Topics

```markdown
1# Make a file with .sh extension.
2# .sh file must have executable permissions.
```


​		

