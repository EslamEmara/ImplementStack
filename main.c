#include "stack.h"
#include <stdio.h>
#include <string.h>

struct node* stack1_head;       // top of the stack
struct node* stack2_head;

void main()
{
  sint_64 return_value1 , return_value2;    // return for pop functions
  uint_8 string[100];
  uint_8 curlyBalanced = 1;               // flag for curly brackets balanced
  uint_8 parBalanced = 1;                 // flag for paranthes balanced

  stack1_head = createStack();          // stack for curly
  stack2_head = createStack();        // stack for paranthes

  while (1)
  {

      printf("enter the string to check: ");
      gets(string);

      for (int i=0;i<strlen(string);i++)
      {
        if (string[i] == '{')
        {
          stack1_head =   push('{',stack1_head);
        }
        else if (string[i] == '}')
        {
          stack1_head =   pop(&return_value1,stack1_head);
          if (return_value1 != '{'){            // if pop from empty stack it'll be unbalanced
            curlyBalanced = 0;
            break;
          }
        }
        else if (string[i] == '(')
        {
          stack2_head =  push('(',stack2_head);
        }
        else if (string[i] == ')')
        {
          stack2_head =  pop(&return_value2,stack2_head);
          if (return_value2 != '('){
          parBalanced = 0;
          break;
          }
        }

      }

      // if both stacks are empty and the flags are high then it'll be balanced
      if (stack1_head->nxt_ptr == NULL && stack2_head->nxt_ptr == NULL &&curlyBalanced == 1 &&parBalanced ==1)
      {
        printf("\nBALANCED!\n");
      }
      else
      {
        printf("\nNOT BALANCED\n");

        /// reset the stacks and flags for the next loop
        while(stack1_head->nxt_ptr != NULL)
          stack1_head =  pop(&return_value1,stack1_head);
        while(stack2_head->nxt_ptr != NULL)
          stack2_head =  pop(&return_value2,stack2_head);
        curlyBalanced = 1;
        parBalanced = 1;

      }
    }
return;
}
