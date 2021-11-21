
Wall = -Wall
CC = gcc

.PHONY : clean 









.PHONY : run


run: prog




prog : my_mat.o main.o 
	${CC} -o prog my_mat.o main.o



my_mat.o : my_mat.c my_mat.h 
	${CC} -c my_mat.c



main.o : main.c my_mat.h
	gcc ${W} -c main.c


clean : 
	rm -f prog *.o