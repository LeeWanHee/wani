#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/miscdevice.h>

int __init init_hello(void)
{
	printk(KERN_ALERT "[Module Message] Hello, Module.\n");
	return 0;
}

void __exit exit_hello(void)
{
	printk(KERN_ALERT "[Module Message] Do you really wnat to break up with me?\n");
}
static struct miscdevice char_dev = 
{
	.minor = MISC_DYNAMIC_MINOR,
	.name = "preempt_test"
	.fops = &char_fops
};

misc_register(&char_dev);
module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
