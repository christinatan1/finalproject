all: main.o questioner.o answerer.o
	gcc -o program main.o questioner.o answerer.o

main.o: main.c headers.h
	gcc -c main.c

questioner.o: questioner.c headers.h
	gcc -c questioner.c

answerer.o: answerer.c headers.h
	gcc -c answerer.c

run:
	./program

clean:
	rm *.o
	rm *~
