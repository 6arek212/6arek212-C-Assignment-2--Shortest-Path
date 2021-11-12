
Wall = -W

.PHONY : clean 


prog : main.o 
	gcc ${W} -o prog main.o



main.o : main.c 
	gcc ${W} -c main.c



clean : 
	rm -f prog *.o