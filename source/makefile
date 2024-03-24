include make.config

ifeq ($(ARCH), i386)
include $(DIR_SOURCE)/arch/i386/make.config

else ifeq ($(ARCH), x64)
include $(DIR_SOURCE)/arch/x64/make.config

else
$(error You must set ARCH flag to your target Architecture)
endif

debug: $(LINKER) 
	$(info Building debug $(ARCH) version)

	make -C $(ARCH_BUILD) INFO_FLAG="$(DEBUG_FLAGS)"
	make -C kernel CXX=$(CXX) INFO_FLAG="$(DEBUG_FLAGS) -D$(ARCH)"
	
	$(CXX) -T $(LINKER) -o $(DIR_BUILDS)/debug/kernel_$(ARCH).bin $(LK_FLAGS) $(ARCH_OBJS)
	@echo -e "Build complete OUT ->$(GREEN) $(DIR_BUILDS)/debug $(END)"


release: $(LINKER)
	$(info Building realse $(ARCH) version)

	make -C $(ARCH_BUILD) INFO_FLAG="$(RELEASE_FLAGS)"
	make -C kernel CXX=$(CXX) INFO_FLAG="$(RELEASE_FLAGS) -D$(ARCH)"

	$(CXX) -T $(LINKER) -o $(DIR_BUILDS)/release/kernel_$(ARCH).bin $(LK_FLAGS) $(ARCH_OBJS)
	@echo -e "Build complete OUT ->$(GREEN) $(DIR_BUILDS)/realse $(END)"
	

mount: $(DIR_BUILDS)/debug/kernel_$(ARCH).bin
	cp $(DIR_BUILDS)/debug/kernel_$(ARCH).bin $(DIR_DISK)/iso/boot/
	grub2-mkrescue -o $(DIR_DISK)/AKICPP.iso $(DIR_DISK)/iso

clean:
	rm $(DIR_OUT)/*.o