cmd_kernel/trace/built-in.o :=  arm-eabi-ld.bfd -EL    -r -o kernel/trace/built-in.o kernel/trace/trace_clock.o kernel/trace/trace-clock-32-to-64.o kernel/trace/trace-clock.o 
