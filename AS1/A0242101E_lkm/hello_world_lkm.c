#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/time.h>

MODULE_AUTHOR("CS5231_TAs"); 
MODULE_DESCRIPTION("CS5231_HelloWorld_loadable_kernel_module");
MODULE_LICENSE("Dual MIT/GPL"); 
MODULE_VERSION("0.1");

static int __init helloworld_lkm_init(void) {
	struct task_struct *task;
	int counter = 0;
	
	for_each_process(task) {
		counter++;
	}
	printk(KERN_INFO "Number of running processes: %d\n", counter);
	printk(KERN_INFO "Current time in seconds: %lld\n", ktime_get_real_seconds());
	return 0; // success
}

static void __exit helloworld_lkm_exit(void) { 
	printk(KERN_INFO "Goodbye, CS5231 Student!\n"); 
}

module_init(helloworld_lkm_init); 
module_exit(helloworld_lkm_exit);
