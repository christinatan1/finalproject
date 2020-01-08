all: main.o questioner.o answerer.o
	gcc -o program main.o questioner.o answerer.o

main.o: main.c header.h
	gcc -c main.c

questioner.o: questioner.c qfunctions.h
	gcc -c shell.c

answerer.o: answerer.c afunctions.h
	gcc -c answerer.c

run:
	./program

clean:
	rm *.o
	rm *~
