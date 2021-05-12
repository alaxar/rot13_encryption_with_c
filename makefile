rot13:	rot13.o
	gcc rot13.o -o rot13

rot13.o: rot13.c
	gcc -c rot13.c

clean:
	rm *.o rot13
