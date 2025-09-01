CC=riscv64-unknown-elf-gcc
SIM=spike pk

.PHONY: run
run: recursive.c
	$(CC) recursive.c recursive.s -o recursive && $(SIM) recursive