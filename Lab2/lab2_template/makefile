# test files
TEST_ALU := tests/alu_test.cpp
TEST_ALUCTRL := tests/alu_ctrl_test.cpp
TEST_MULT := tests/multiplier_test.cpp

define BUILD_RUN
	verilator -Wall -Wno-UNUSEDSIGNAL --cc $(1).v --exe $(2) --trace
	make -C obj_dir -f V$(1).mk V$(1)
	./obj_dir/V$(1)
endef

.PHONY: main help alu alu_ctrl multiplier clean

help main: 
	@echo "Usage: "
	@echo "  make alu 		- build & run ALU"
	@echo "  make alu_ctrl		- build & run ALUCtrl"
	@echo "  make multiplier	- build & run Multiplier"

alu: clean
	$(call BUILD_RUN,ALU,$(TEST_ALU))

alu_ctrl: clean
	$(call BUILD_RUN,ALUCtrl,$(TEST_ALUCTRL))

multiplier: clean 
	$(call BUILD_RUN,Multiplier,$(TEST_MULT))

clean:
	rm -rf obj_dir
	rm -f waveform.vcd
