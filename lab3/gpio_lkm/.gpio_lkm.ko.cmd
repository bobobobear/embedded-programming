cmd_/home/ubuntu/embedded-programming/lab3/gpio_lkm/gpio_lkm.ko := ld -r  -EL  -maarch64elf  --build-id  -T ./scripts/module-common.lds -T ./arch/arm64/kernel/module.lds -o /home/ubuntu/embedded-programming/lab3/gpio_lkm/gpio_lkm.ko /home/ubuntu/embedded-programming/lab3/gpio_lkm/gpio_lkm.o /home/ubuntu/embedded-programming/lab3/gpio_lkm/gpio_lkm.mod.o;  true
