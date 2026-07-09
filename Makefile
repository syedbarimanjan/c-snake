CC=gcc

main: main.c
	$(CC) main.c stb_ds.c -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: main
	./main

clean:
	rm main

a:
	make clean && make main && make run

main-safe: main.c
	$(CC) -fsanitize=address -g main.c stb_ds.c -o main-safe -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run-safe: main-safe
	LD_PRELOAD=/usr/lib64/libasan.so.8 ./main-safe

clean-safe:
	rm main-safe

b:
	make clean-safe && make main-safe && make run-safe