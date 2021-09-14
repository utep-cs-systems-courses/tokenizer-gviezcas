main: main.o tokenizer.o
	gcc -o main main.o tokenizer.o

main.o: main.c
	gcc -c main.c
tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c
clean:
	rm *.o *~ main
