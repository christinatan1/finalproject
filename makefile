all: main.o questioner.o answerer.o
	gcc -o program main.o questioner.o answerer.o

main.o: main.c headers.h
	gcc -c main.c

questioner.o: questioner.c headers.h
	gcc -c questioner.c

answerer.o: answerer.c headers.h
	gcc -c answerer.c

server: select_server.o networking.o
	gcc -o server select_server.o networking.o

client: client.o networking.o
	gcc -o client client.o networking.o

client.o: client.c networking.h
	gcc -c client.c

select_server.o: select_server.c headers.h
	gcc -c select_server.c

networking.o: networking.c headers.h
	gcc -c networking.c

run:
	./program

clean:
	rm *.o
	rm *~
