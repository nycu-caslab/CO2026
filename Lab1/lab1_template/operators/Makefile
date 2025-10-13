CC=riscv64-unknown-elf-gcc
SIM=spike pk

.PHONY: run
run: main.c
	$(CC) main.c main.s -o main && $(SIM) main