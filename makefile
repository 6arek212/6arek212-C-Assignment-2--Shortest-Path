
Wall = -Wall
CC = gcc

.PHONY : clean
.PHONY : all


all: connections



connections : my_mat.o main.o 
	${CC} ${Wall} -o connections my_mat.o main.o



my_mat.o : my_mat.c my_mat.h 
	${CC} ${Wall} -c my_mat.c



main.o : main.c my_mat.h
	${CC} ${Wall} -c main.c


clean : 
	rm -f connections *.o