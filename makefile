all: main.o questioner.o answerer.o networking.o
	gcc -o program main.o questioner.o answerer.o networking.o

main.o: main.c headers.h
	gcc -c main.c

questioner.o: questioner.c headers.h
	gcc -c questioner.c

answerer.o: answerer.c headers.h
	gcc -c answerer.c

networking.o: networking.c headers.h
	gcc -c networking.c

run:
	./program

clean:
	rm *.o
	rm *~
