.PHONY: main clean

main: clean
	verilator -Wall -Wno-UNUSEDSIGNAL --cc SingleCycleCPU.v --exe example_testbench.cpp --trace
	make -C obj_dir -f VSingleCycleCPU.mk VSingleCycleCPU
	./obj_dir/VSingleCycleCPU

clean:
	rm -rf obj_dir
	rm -f waveform.vcd


