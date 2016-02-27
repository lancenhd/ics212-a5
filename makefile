homework5: main.o iofunctions.o  
	gcc -o homework5 main.o iofunctions.o 

main.o: main.c iofunctions.h  
	gcc -c main.c 

iofunctions.o: iofunctions.c iofunctions.h account.h
	gcc -c iofunctions.c 

clean:
	rm *.o homework5  
