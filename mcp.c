#include <linux/module.h>

void mcp_print(int value)
{
	printk("In %s, value = %d\n", __FUNCTION__, value);
}
EXPORT_SYMBOL(mcp_print);


static int __init mcp_init(void)
{
	printk("Enter: %s\n", __FUNCTION__);
	return 0;
}

static void __exit mcp_exit(void)
{
	printk("Enter: %s\n", __FUNCTION__);
}

module_init(mcp_init);
module_exit(mcp_exit);

MODULE_LICENSE("GPL");

