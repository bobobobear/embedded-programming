#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h> /* for put_use and get_user */

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);


static struct file_operations fops = { .read = device_read,
.write = device_write,
.open = device_open,
.release = device_release
};

char msg_buf[20], ctr = 0; // buffer to store message from user space
int errorno;


static int __init ce3103_init(void)
{
    printk(KERN_ALERT "Loading modIO\n");
    register_chrdev(101, "ce3103", &fops);
    return(0);
}

static void __exit ce3103_cleanup(void)
{
    unregister_chrdev(101, "ce3103");
    printk(KERN_ALERT "Unloading modIO\n");
}

static int device_open(struct inode *inode, struct file *file)
{ 
    printk(KERN_ALERT "Someone opened modIO\n");
    return 0; 
}

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_ALERT "Someone closed modIO\n");
    return 0; 
}
static ssize_t device_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
    printk(KERN_ALERT "reading the device 101\n");
    if (ctr==0)
        return 0; /* nothing to return to userland*/
    errorno = copy_to_user(buf, msg_buf, 12); /* write to user space */
    ctr=0;
    return 1;
}

static ssize_t device_write(struct file *filp, const char *buf, size_t len, loff_t *off)
{ 
    printk(KERN_ALERT "writing to device 101\n");
    if (ctr>0)
        return 0; /* no space to accept another char */
    errorno = copy_from_user(msg_buf, buf, 12); /* retrieve value from user space */
    ctr=1;
    return 1; /* 1 message read from buffer*/
}


module_init(ce3103_init);
module_exit(ce3103_cleanup);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CE3103");
MODULE_DESCRIPTION("Simple module – v3");