
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "types.h"

// linkedlist node

struct node
{
    sint_64 data;
    struct node *nxt_ptr;
};

//functions protoypes

struct node * push(sint_64 data,struct node*);
struct node* pop(sint_64 *return_value,struct node* head);
void print_stack(struct node*);
struct node* createStack();

#endif
