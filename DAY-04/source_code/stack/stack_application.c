#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
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

void infix_to_postfix(char *in, char *post);
int priority(char opr) ;
bool_t is_operand(char ch);


int main(void)
{
    char infix[32] = "a*b/c*d/e+f-g+h/i";
    char postfix[32] = " ";

    printf("infix expression is: %s\n", infix);
    
    infix_to_postfix(infix, postfix);

    printf("postfix expression is: %s\n", postfix);
    return 0;
}

bool_t is_operand(char ch)
{
    return ( ( ch >= 65 && ch <= 90 ) || ( ch >= 97 && ch <= 122 ) || ( ch >= 48 && ch <= 57 ) );
}

//inside this function we defining priority for operators programmatically
int priority(char opr) 
{
    switch( opr )
    {
        case '+':
        case '-': return 1;

        case '*':
        case '/':
        case '%': return 2;
    }
}

void infix_to_postfix(char *in, char *post)
{
    stack_t s;
    init_stack(&s);
    int i;
    int j=0;

    //step-1: start scanning infix expression from left to right till the end of postfix expression
    for( i = 0 ; in[ i ] != '\0' ; i++ )
    {
        //step-2:
        if( is_operand( in[i] ) )//if( cur ele is an operand )
        {
            //append it into the postfix expression
            post[ j++ ] = in[i];
        }
        else//if( cur ele is an operator )
        {
            while( !is_stack_empty(&s) && priority( peek_element(&s) ) >= priority(in[i]) )
            {
                //pop ele from the stack and append it into the postfix expression
                post[ j++ ] = peek_element(&s);
                pop_element(&s);
            }

            //push cur ele onto the stack
            push_element(&s, in[i]);
        }
    }//step-3: repeat above steps till the end of postfix expression

    //step-4: pop all remaining elements from the stack one by one and append them into the postfix expression.
    while( !is_stack_empty(&s)){
        post[ j++ ] = peek_element(&s);
        pop_element(&s);
    }
    post[j] = '\0';
}

void init_stack(stack_t *ps)
{
    ps->top = -1;
}

bool_t is_stack_full(stack_t *ps)
{
    return ( ps->top == SIZE-1 );
}

bool_t is_stack_empty(stack_t *ps)
{
    return ( ps->top == -1 );
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






