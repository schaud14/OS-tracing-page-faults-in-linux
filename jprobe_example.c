#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/time.h>
#include <linux/timekeeping.h>
#include <linux/moduleparam.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

/*
input  = process id
*/
int current_proc_id = 0;
module_param(current_proc_id, int, S_IRUSR | S_IWUSR);
int ij;
static int count = 0;
char buffdata[100];
long buffer[200];

static struct file_operations fops;

struct Data
{
	long time;
	long address;
};
struct Data databuffer[100];

/*
This function will get called when proc file is opened
*/
int open_proc_mod(struct inode * sp_inode, struct file *sp_file)
{
    printk(KERN_INFO "proc called open\n");
    return 0;
}

/*
This function will get call when proc file will get closed
*/
int release_proc_mod(struct inode *sp_indoe, struct file *sp_file)
{
    printk(KERN_INFO "proc called release\n");
    return 0;
}


/*
This function will get called when read operation is done on proc file
*/
static int read_proc_mod(struct file *sp_file,char __user *buf, size_t size, loff_t *offset)
{
int i;	
ij--;
    printk(KERN_INFO "proc called read\n");	
	snprintf(buffdata,100,"Address: %lx Time: %li",databuffer[ij].address,databuffer[ij].time);
	printk(KERN_INFO "%s\n",buffdata);
	i = copy_to_user(buf,buffdata,100);
	if(i !=0)
{
    printk(KERN_INFO "error copying %d bytes\n",i);
}
    return count*(sizeof(struct Data));
}


/*
This function will get called when write operation is done on proc file
*/
int write_proc_mod(struct file *sp_file,const char __user *buf, size_t size, loff_t *offset)
{
    int i;
    printk(KERN_INFO "proc called write \n");
    //memcpy(buffer1,datab ,100*(sizeof(struct Data)));
    /*for(i =0,j=0; i<count;i++,j+2){
    buffer[j] = databuffer[i].address;
    buffer[j+1] = databuffer[i].time;
    }*/
    i = copy_from_user(buffer,databuffer,count*(sizeof(struct Data)));
    if (i != 0 )
    {
        return -EFAULT;
    }
	//memcpy(buf,buffer,count*(sizeof(struct Data));
    return count*(sizeof(struct Data));
}

/*
Structure for file operarions 
*/
static struct file_operations fops = {
    .open = open_proc_mod,
    .read = read_proc_mod,
    .write = write_proc_mod,
    .release = release_proc_mod
};



/*
Modified function for page fault detection.
*/
int my_handle_mm_fault(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, unsigned int flags)
{
    /*
    Get Current time.
    */

	if (current->pid == current_proc_id)
    {
        printk(KERN_ALERT "Current PID: %d \n",current->pid);
        struct timespec current_time;
        getnstimeofday(&current_time);
        current_time.tv_nsec = (current_time.tv_sec * 1000000000)+current_time.tv_nsec;
        //printk(KERN_ALERT "The Current Time in Seconds is : %li\n",current_time->tv_sec);
        printk(KERN_ALERT "Faulting Address: %lx, Time of Fault: %li\n", address,current_time.tv_nsec);
	   /*
        This will store the first 100 page faults in kernel memory.
       */
       if(count < 100)
        {
        	databuffer[count].address = address;
        	databuffer[count].time = current_time.tv_nsec;
        	count++;
		ij++;
        }
    }
	jprobe_return();

	return 0;
}

/*
jprobe structure
*/
static struct jprobe my_jprobe = 
{
    .entry = my_handle_mm_fault,
    .kp = { 
        .symbol_name    = "handle_mm_fault",
        },
};


/*
this is init function called when module is inserted.
*/
static int __init jprobe_init(void)
{
    /*
    Registering jprobe
    */
    int ret;
    ret = register_jprobe(&my_jprobe);
    if (ret < 0) 
    {
        printk(KERN_INFO "unable to register jprobe %d\n", ret);
        return -1;
    }
    printk(KERN_INFO "Planted jprobe at %p, handler addr %p\n",my_jprobe.kp.addr, my_jprobe.entry);
	
    printk(KERN_INFO "creating proc file\n");
    /*
    creating proc file
    */
    if (!proc_create("myprocfile",0666,NULL,&fops)) 
    {
        printk(KERN_INFO "ERROR in creating myprocfile\n");
        remove_proc_entry("myprocfile",NULL);
        return -1;
    }
    return 0;
}


/*
this exit function will get called when module is removed.
*/
static void __exit jprobe_exit(void)
{
    unregister_jprobe(&my_jprobe);
    printk(KERN_INFO "jprobe at %p unregistered\n", my_jprobe.kp.addr);
    remove_proc_entry("myprocfile",NULL);
    printk(KERN_INFO "exit simple proc\n");
}

module_init(jprobe_init);
module_exit(jprobe_exit);
MODULE_LICENSE("GPL");
