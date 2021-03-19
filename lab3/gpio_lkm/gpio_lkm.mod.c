#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x246ec1f5, "module_layout" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x25c379f2, "gpiod_to_irq" },
	{ 0x94603c9e, "gpiod_set_debounce" },
	{ 0x27ded2da, "gpiod_direction_input" },
	{ 0xa928d81e, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xfe990052, "gpio_free" },
	{ 0xc5850110, "printk" },
	{ 0xa89a61ac, "gpiod_set_raw_value" },
	{ 0xd9c00360, "gpio_to_desc" },
	{ 0x1fdc7df2, "_mcount" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0284BF83DD88FD075600109");
