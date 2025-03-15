#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

//firewall.c
//Linux module

MODULE_DESCRIPTION("Firewall");
MODULE_AUTHOR("Kaylem20201");
MODULE_LICENSE("MIT");

static int module_init(void)
{
        pr_debug("Firewall module initiated\n");
        return 0;
}

static void module_exit(void)
{
        pr_debug("Firewall module terminated\n");
}

module_init(dummy_init);
module_exit(dummy_exit);
