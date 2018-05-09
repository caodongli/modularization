#include <linux/module.h>
#include <linux/kvm_host.h>

static int value = 5;
static char *name = "test";
module_param(value, int, 0444);
module_param(name, charp, 0755);

//extern struct medium_ops *medium_ops;
struct medium_ops *medium_ops __read_mostly;
EXPORT_SYMBOL(medium_ops);

/*
int ops_init(void *opaque)
{
	struct medium_ops *ops = opaque;
	
	medium_ops = ops;

	return 0;
}
EXPORT_SYMBOL(ops_init);
*/
int pcm_init(void *opaque)
{
	struct medium_ops *ops = opaque;

	medium_ops = ops;

	printk("Enter: %s\n", __FUNCTION__);
	
	medium_ops->call_itr_print(6);	

	return 0;
}
EXPORT_SYMBOL(pcm_init);

void pcm_exit(void)
{
	printk("Exit: %s\n", __FUNCTION__);
}
EXPORT_SYMBOL(pcm_exit);
//module_init(pcm_init);
//module_exit(pcm_exit);

MODULE_LICENSE("GPL");

