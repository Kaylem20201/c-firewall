#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

//firewall.c
//Linux module

MODULE_DESCRIPTION("Firewall");
MODULE_AUTHOR("Kaylem20201");
MODULE_LICENSE("GPL");

static int firewall_init(void)
{
        printk("Firewall module initiated\n");
        return 0;
}

static void firewall_exit(void)
{
        printk("Firewall module terminated\n");
}

module_init(firewall_init);
module_exit(firewall_exit);
