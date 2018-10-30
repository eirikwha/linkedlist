#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{

    list_t list;
    list = malloc(sizeof(struct list));
    list ->head = NULL;
    list ->tail = NULL;
    list ->length = 0;
    return list;

}

void list_delete(list_t list) {
    struct node *current = list->head;
    if (current == NULL) {
        return;
    }
        current = list ->head;
        current = current->next;
        free(current);
        //current->next = current;
    list_delete(current-> next);
    free(current);


}

void list_insert(list_t list, int index, int data) // see more here: https://stackoverflow.com/questions/44193596/insert-element-at-nth-position-in-the-linked-list-c
{

        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        //Creating a new node
        ptr->data=data;

        int i;
        struct node *temp=list->head;
        //Do not use the pointer variable head directly. If we use it, the address location of the first node in the linked list will be lost
        //Pointer variable temp is used to traverse the linked list


        if(index==0)
        {
            //Executed only if index is 1
            //If index is 1, it is a special case because we need to nodify the head  pointer
            ptr->next=temp;
            //ptr->next=head is also valid;

            list->head=ptr;
            //Making head point to newly created node ptr
            return;
        }

        //Function to insert node at index n in the linked list
        //If we have  5nodes in the linked list, we can insert a new a node between any two nodes of the five nodes present in the linked list

        for(i=0;i<index-1;i++)//Traversing to the (n-1)th index node in the linked list
        {
            temp=temp->next;
        }

        ptr->next=temp->next;
        //Making the newly created node point to next node of pointer temp

        temp->next=ptr;
        //Making pointer temp point to newly created node in the linked list
        list->length = list->length + 1;

}

void list_append(list_t list, int data)
{
    struct node * current = list->head;
    struct node * new = malloc(sizeof(struct node)); /* Make a pointer to "new", and allocate memory for it */
    if (current == NULL) {
        list ->head = new;
        new ->data = data;
        new ->next = NULL;
        new ->prev = NULL;
    }
    else {
        while (current ->next != NULL) {
            current = current ->next;
        }
        current -> next = new;
        new -> data = data;
        new -> next = NULL;
        new -> prev = current;
    }
        list -> length += 1;
        return list;
}

void list_print(list_t list)
{
    struct node * current = list->head;
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }   printf("\n");
}

long list_sum(list_t list)
{
    int sum = 0;
    struct node * current = list->head; /*use for-loop to define this, here the list->head is unneccesary*/
    for (current = list->head; current !=NULL; current = current -> next) {
        sum = sum + current->data;
    }
    return sum;

}


int list_get(list_t list, int index) {
    // Takes head pointer of
    // the linked list and index
    // as arguments and return
    // data at index

    struct node *current = list->head;

    // the index of the
    // node we're currently
    // looking at
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
}
int list_extract(list_t list, int index) { // current er den før index value, den som skal fjernes er temp // først current next = temp, så current next = temp next


    int i = 0;
    int retval;
    struct node* current = list->head;
    struct node* temp = NULL;

    if (index == 0)
    {
        retval = current->data;
        list->head = current->next;
        free(current);
    }
    else
    {
        for (i = 0; i < index-1; i++)
        {
            if (current->next == NULL)
            {
                return -1;
            }
            current = current->next;
        }

        temp = current->next;
        retval = temp->data;
        current->next = temp->next;
        free(temp);
    }
    list->length = list->length - 1;

    return retval;

}
