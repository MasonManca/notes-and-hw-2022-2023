/*
Mason Manca
CPSC 346
Project 6: Linux Kernel Module
5 December 2022
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/printk.h>

struct person {
    int month;
    int day; 
    int year;
    struct person* next;
};

struct person* ptr = NULL;

void addPerson(struct person** pptr, int month, int day, int year) {
    struct person* temp = (*pptr);
   
    // allocate new person node
    struct person* newNode = (struct person*)kmalloc(sizeof(struct person), GFP_KERNEL);
    newNode->month = month;
    newNode->day = day;
    newNode->year = year;
    newNode->next = NULL;
    
    // add new person node to list
    if ((*pptr) == NULL) {
        (*pptr) = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(struct person** head) {
    struct person* temp = (*head);
    
    while (temp != NULL) {
        printk(KERN_INFO "Month: %d\n", temp->month);
        printk(KERN_INFO "Day: %d\n", temp->day);
        printk(KERN_INFO "Year: %d\n", temp->year);
        
        temp = temp->next;
    }
}
/* This function is called when the module is loaded. */
int simple_init(void) {
    printk(KERN_INFO "Loading Module\n");
    
    addPerson(&ptr, 1, 24, 2002);
    addPerson(&ptr, 10, 1, 2000);
    addPerson(&ptr, 5, 4, 2008);
    addPerson(&ptr, 7, 17, 20014);
    addPerson(&ptr, 5, 3, 1907);
    
    printList(&ptr);

   return 0;
}
/* This function is called when the module is removed. */
void simple_exit(void) {
    printk(KERN_INFO "Removing Module\n");
    ptr = NULL;
}
/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
