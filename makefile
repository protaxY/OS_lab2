all:main.c child.c
	gcc -O2 -std=c++14 -o main main.c 
	gcc -O2 -std=c++14 -o child child.c

