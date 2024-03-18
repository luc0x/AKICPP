include make.config

ifeq ($(ARCH), i386)
include $(DIR_SOURCE)/arch/i386/make.config

else ifeq ($(ARCH), x64)
include $(DIR_SOURCE)/arch/x64/make.config

endif

debug: $(LINKER)
	@echo "Building..."
	make -C $(ARCH_BUILD) INFO_FLAG="$(DEBUG_FLAGS)"
	make -C kernel CXX=$(CXX) INFO_FLAG="$(DEBUG_FLAGS)"
	
	@echo "Linking..."
	$(CXX) -T $(LINKER) -o $(DIR_BUILDS)/debug/kernel_$(ARCH).bin $(LK_FLAGS) $(ARCH_OBJS)

	@echo "Build and Link complete!" 
	


release: $(LINKER)

mount: $(DIR_BUILDS)/debug/kernel_$(ARCH).bin
	cp $(DIR_BUILDS)/debug/kernel_$(ARCH).bin $(DIR_DISK)/iso/boot/
	grub2-mkrescue -o $(DIR_DISK)/AKICPP.iso $(DIR_DISK)/iso

clean:
	rm $(DIR_OUT)/*.o