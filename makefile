stat: main.o
	gcc -o stat main.o
	make clean

main.o: main.c
	gcc -c main.c

clean:
	rm *.o

run:
	./stat
