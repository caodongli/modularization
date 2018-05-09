#include <linux/module.h>
#include <linux/kvm_host.h>

//extern void mcp_print(int);

static void vmx_itr_print(int value)
{
	mcp_print(value);
}

//struct medium_ops *medium_ops __read_mostly;
//EXPORT_SYMBOL(medium_ops);

static struct medium_ops vmx_medium_ops = {
	.call_itr_print = vmx_itr_print,
};




static int __init medium_init(void)
{
	printk("Enter: %s\n", __FUNCTION__);

//	vmx_medium_ops.call_itr_print(8);

//	medium_ops = &vmx_medium_ops;
	
//	medium_ops->call_itr_print(10);

//	ops_init(&vmx_medium_ops);

	pcm_init(&vmx_medium_ops);
		
	return 0;
}

static void __exit medium_exit(void)
{
	printk("Exit: %s\n", __FUNCTION__);
	pcm_exit();
}


module_init(medium_init);
module_exit(medium_exit);

MODULE_LICENSE("GPL");

