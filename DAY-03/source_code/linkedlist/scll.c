#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node_t;

node_t *head = NULL;


void add_node_at_last_position(int data);
void display_list(void);

int main(void)
{
    add_node_at_last_position(10);
    add_node_at_last_position(20);
    add_node_at_last_position(30);
    add_node_at_last_position(40);
    add_node_at_last_position(50);

    display_list();


    return 0;
}

node_t *create_node(int data)
{
    //1. allocate memory dynamically for a node
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    /* on success, malloc() allocates requested bytes of memory from heap section and returns
    starting addr of dynamically allocated block, whereas on failure it returns NULL */
    if( temp == NULL )//error handling
    {
        printf("malloc() failed !!!\n");
        exit(1);
    }
    //2. initialize members of the node
    temp->data = data;
    temp->next = NULL;
    //3. return starting addr of dynamically allocated node/block to the calling function
    return temp;

}

void add_node_at_last_position(int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);
    //step-2: if list is empty - attach newly created node to the head
    if( head == NULL )
    {
        head = newnode;
        newnode->next = head;
    }
    else//step-3: if list is not empty
    {
        node_t *trav = head;
        //traverse the list till last node
        while( trav->next != head )
            trav = trav->next;

        //attach newly created node to the last node
        trav->next = newnode;
        //store an addr of first into the next part of newly created node
        newnode->next = head;
    }
}

void display_list(void)
{
    //if list is not empty
    if( head != NULL )
    {
        //start traversal from the first node
        node_t *trav = head;
        printf("list is: head -> ");
        //traverse the list till last node (including it)
        do{
            printf("%d -> ", trav->data);//display data part of each node
            trav = trav->next;//move trav pointer towards its next node
        }while( trav != head );
        printf("head\n");
    }
    else
        printf("list is empty !!!\n");

}