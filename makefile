prog: Pendu.o main.o 
	g++ Pendu.o main.o -o prog
Pendu.o: Pendu.c
	g++ -c Pendu.c
main.o: main.c
	g++ -c main.c
clean:
	rm *.o prog