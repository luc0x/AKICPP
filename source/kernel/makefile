include ../make.config

kernel.o: $(DIR_INCLUDE)/kernel/kernel.hpp multiboot.o
	$(CXX) $(CXX_FLAGS) $(INFO_FLAG) kernel.cpp -o $(DIR_OUT)/kernel.o

multiboot.o: $(DIR_INCLUDE)/multiboot/multiboot.hpp multiboot.cpp
	$(CXX) $(CXX_FLAGS) $(INFO_FLAG) multiboot.cpp -o $(DIR_OUT)/multiboot.o

