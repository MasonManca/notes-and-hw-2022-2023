/*
Name: Jesse Adams
Class: CPSC 346 Fall 2022
Date: 11/5/2022
Assignment: Project 6
Notes:
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/printk.h>

struct person {
    int month, day, year;
    struct person* next;
};

struct person* headPtr = NULL;

void addPerson(struct person** head, int month, int day, int year) {
    struct person* mover = (*head);
   
    // allocate new person node
    struct person* newNode = (struct person*)kmalloc(
        sizeof(struct person), GFP_USER);
    newNode->month = month;
    newNode->day = day;
    newNode->year = year;
    newNode->next = NULL;
    
    // add new person node to list
    if ((*head) == NULL) {
        (*head) = newNode;
    } else {
        while (mover->next != NULL) {
            mover = mover->next;
        }
        mover->next = newNode;
    }
}

void printList(struct person** head) {
    struct person* mover = (*head);
    
    while (mover != NULL) {
        printk(KERN_INFO "Month: %d\n", mover->month);
        printk(KERN_INFO "Day: %d\n", mover->day);
        printk(KERN_INFO "Year: %d\n", mover->year);
        
        mover = mover->next;
    }
}

/* This function is called when the module is loaded. */
int simple_init(void) {
    printk(KERN_INFO "Loading Module\n");
    
    addPerson(&headPtr, 10, 30, 2022);
    addPerson(&headPtr, 11, 23, 2011);
    addPerson(&headPtr, 1, 15, 2003);
    addPerson(&headPtr, 4, 6, 2008);
    addPerson(&headPtr, 8, 17, 1998);
    
    printList(&headPtr);

   return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
    printk(KERN_INFO "Removing Module\n");
    headPtr = NULL;
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
