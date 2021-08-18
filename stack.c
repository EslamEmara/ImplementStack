
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"




struct node* createStack()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->nxt_ptr = NULL;
    return head;
}

struct node *  push(sint_64 data,struct node* head)
{
    struct node* temp;

        temp =(struct node *)malloc(sizeof(struct node));
        temp->nxt_ptr = head;
        temp->data = data;
        head = temp;

    return head;
}


struct node* pop(sint_64 *return_value,struct node* head)
{
    struct node *temp;
    temp = head;

    if (head->nxt_ptr == NULL)
    {
        *return_value = 0; 
        return head;
    }
    else

        temp = temp->nxt_ptr;
        *return_value = head->data;
        free(head);
        head = temp;

    return head;
}

void print_stack(struct node* head)
{
    struct node* temp;
    temp = head;

    if (head->nxt_ptr == NULL)
    {
        printf("The stack is empty!!\n");
        return;
    }

    while (temp->nxt_ptr != NULL)
    {
        printf("%ld ", temp->data);
        temp = temp->nxt_ptr;
    }
 }
