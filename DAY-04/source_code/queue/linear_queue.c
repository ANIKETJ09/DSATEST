//implementation of linear queue:

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef int bool_t;

typedef struct 
{
    int arr[ SIZE ];
    int rear;
    int front;
}queue_t;

void init_queue(queue_t *pq);
bool_t is_queue_full(queue_t *pq);
bool_t is_queue_empty(queue_t *pq);
void enqueue(queue_t *pq, int ele);
void dequeue(queue_t *pq);
int get_front(queue_t *pq);

int menu(void)
{
    int choice;

    printf("***** linear queue *****\n");
    printf("0. exit\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("enter the choice: ");
    scanf("%d", &choice);

    return choice;
}

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int main(void)
{
    queue_t q;
    int ele;

    init_queue(&q);

    while(1)
    {
        int choice = menu();
        switch (choice)
        {
        case EXIT:
            exit(0);

        case ENQUEUE:
            //step-1: check queue is not full (if queue is not full then only we can insert an ele into it)
            if( !is_queue_full(&q) )
            {
                printf("enter element: ");
                scanf("%d", &ele);
                enqueue(&q, ele);
                printf("%d inserted into the queue ...\n", ele);
            }
            else
                printf("queue is full !!!\n");

            break;

        case DEQUEUE:
            //step-1: check queue is not empty (if queue is not empty then only we can delete an ele from it)
            if( !is_queue_empty(&q) )
            {
                ele = get_front(&q);
                dequeue(&q);
                printf("deleted ele is: %d\n", ele);
            }
            else
                printf("queue is empty !!!\n");   

            break;
        }

    }

    return 0;
}

void init_queue(queue_t *pq)
{
    pq->front = pq->rear = -1;
}

bool_t is_queue_full(queue_t *pq)
{
    return ( pq->rear == SIZE-1 );
}

bool_t is_queue_empty(queue_t *pq)
{
    return ( pq->rear == -1 || pq->front > pq->rear );
}

void enqueue(queue_t *pq, int ele)
{
    //step-2: increment the value of rear by 1
    pq->rear++;

    //step-3: insert an ele into the queue from rear end
    pq->arr[ pq->rear ] = ele;

    /* step-4: if( front == -1 )
            front = 0 */
    if( pq->front == -1 )
        pq->front = 0;
}

void dequeue(queue_t *pq)
{
    //step-2: increment the value of front by 1 [ i.e. we are deleting an ele from queue ]
    pq->front++;
}

int get_front(queue_t *pq)
{
    //return the value of an ele which is at front position
    return ( pq->arr[ pq->front ] );
}








