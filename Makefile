CC=gcc

main: main.c
	$(CC) main.c stb_ds.c -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: main
	./main

clean:
	rm main

a:
	make clean && make main && make run