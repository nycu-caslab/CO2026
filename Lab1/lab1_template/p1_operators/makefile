CC := riscv64-unknown-elf-gcc
SIM := spike
PK := pk

.PHONY: run test

main: main.c main.s
	$(CC) main.c main.s -o main

test: main
	@ for f in testcases/*; do \
		echo "===== $$f ====="; \
		$(SIM) $(PK) ./main < "$$f";\
	done

run: main
	$(SIM) $(PK) main

clean: main
	rm -f main