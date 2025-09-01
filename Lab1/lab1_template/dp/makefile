CC=riscv64-unknown-elf-gcc
SIM=spike pk

.PHONY: run
run: dp.c
	$(CC) dp.c dp.s -o dp && $(SIM) dp