//implementation of static_stack
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
#define true 1
#define false 0


typedef int bool_t; 

typedef struct
{
    int arr[ SIZE ];
    int top;
}stack_t;


void init_stack(stack_t *ps);
bool_t is_stack_full(stack_t *ps);
bool_t is_stack_empty(stack_t *ps);
void push_element(stack_t *ps, int ele);
void pop_element(stack_t *ps);
int peek_element(stack_t *ps);

int menu(void)
{
    int choice;

    printf("***** static stack *****\n");
    printf("0. exit\n");
    printf("1. push element\n");
    printf("2. pop element\n");
    printf("3. peek element\n");
    printf("enter the choice: ");
    scanf("%d", &choice);

    return choice;
}

enum menu_options{ EXIT, PUSH, POP, PEEK };

int main(void)
{
    stack_t s;
    int ele;

    init_stack(&s);

    while(1)
    {
        int choice = menu();
        switch(choice)
        {
            case EXIT:
                exit(0);

            case PUSH:
                //step-1 : check stack is not full
                //(if stack is not full then only we can push ele onto the stack).
                if( !is_stack_full(&s) )
                {
                    printf("enter an ele: ");
                    scanf("%d", &ele);
                    push_element(&s, ele);
                    printf("%d is pushed onto the stack ....\n", ele);
                }
                else
                    printf("stack overflow !!!\n");

                break;

            case POP:
                //step-1 : check stack is not empty
                //(if stack is not empty then only we can pop ele from the stack).
                if( !is_stack_empty(&s) )
                {
                    ele = peek_element(&s);
                    pop_element(&s);
                    printf("popped ele is: %d\n", ele);
                }
                else
                    printf("stack underflow !!!\n");
                break;

            case PEEK:
                //step-1 : check stack is not empty
                //(if stack is not empty then only we can pop ele from the stack).
                if( !is_stack_empty(&s) )
                {
                    ele = peek_element(&s);
                    printf("topmost ele is: %d\n", ele);
                }
                else
                    printf("stack underflow !!!\n");

                break;
        }
    }

    return 0;
}

void init_stack(stack_t *ps)
{
    ps->top = -1;
}

bool_t is_stack_full(stack_t *ps)
{
    return ( ps->top == SIZE-1 );
    /*
    if( ps->top == SIZE-1 )
        return true;
    else
        return false;
    */
}

bool_t is_stack_empty(stack_t *ps)
{
    return ( ps->top == -1 );
    /*
    if( ps->top == -1 )
        return true;
    else
        return false;
    */
}

//op1 += op2; => op1 = op1 + op2;

void push_element(stack_t *ps, int ele)
{
    //step-2 : increment the value of top by 1
    ps->top++;//ps->top = ps->top + 1;

    //step-3: insert/push an element onto the stack at top position/end
    ps->arr[ ps->top ] = ele;
}

void pop_element(stack_t *ps)
{
    //step-2 : decrement the value of top by 1 [ i.e. we are deleting an ele from the stack ] 
    ps->top--;
}

int peek_element(stack_t *ps)
{
    //step-2 : get/return the value of topmost element (without incrementing/decrementing top)
    return ( ps->arr[ ps->top ] );
}






