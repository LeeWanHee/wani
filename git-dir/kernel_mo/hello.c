#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/miscdevice.h>

static struct miscdevice hello_dev;

int hello_open(void)
{
	printk(KERN_ALERT "open pen\n");
	return 0;
}

int __init init_hello(void)
{
	misc_register(&hello_dev);
	printk(KERN_ALERT "[Module Message] Hello, Module.\n");
	return 0;
}

void __exit exit_hello(void)
{
	printk(KERN_ALERT "[Module Message] Do you really wnat to break up with me?\n");
}
static struct file_operations hello_fops={
.open = hello_open,
};

static struct miscdevice hello_dev={
	253, "hello_misc",&hello_fops };

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
