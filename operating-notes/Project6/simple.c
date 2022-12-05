/*
Mason Manca
CPSC 346 Section: 2
Dr. Zhang
Project 6
5 December 2022
*/
// Do not use the Kernel data structure functions
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct person {
       int day;
       int month;
       int year;
       struct list_head list;
}; node;

node* pptr;

void makeNode(node** ptr){
       node* newNode = (node*) kmalloc(sizeof(node), GFP_USER);
       newNode -> month = 10;
       newNode -> day = 8;
       newNode -> year = 2019;
       newNode -> next = NULL;
       *ptr = newNode;
}

void printNode(node* ptr){
       if(ptr != NULL){
              printk(KERN_INFO "Month: %d\n", ptr -> month);
              printk(KERN_INFO "Day: %d\n", ptr -> day);
              printk(KERN_INFO "Year: %d\n", ptr -> year);
              printk(KERN_INFO "Next: %p\n", ptr -> next);
       }
       else{
              printk(KERN_INFO "Node is NULL\n");
       }
}
/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
              makeNode(&pptr);
              printNode(pptr);
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
       pptr = NULL;
       printNode(pptr);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
