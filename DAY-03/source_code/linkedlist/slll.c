
#include<stdio.h>
#include<stdlib.h>

//define "node"
typedef struct node
{
    int data;//4 bytes
    struct node *next;//self referential pointer - 4 bytes - on 32-bit compiler
}node_t;

//create an empty linked list
node_t *head = NULL;

void add_node_into_list_at_last_position(int data);
void add_node_into_list_at_first_position(int data);
void add_node_into_list_at_specific_position(int pos, int data);
void delete_node_at_first_position(void);
void delete_node_at_last_position(void);
void delete_node_at_specific_position(int pos);
node_t *create_node(int data);
void display_list(void);
int count_nodes(void);


int menu(void)
{
    int choice;

    printf("singly linear linked list operations\n");
    printf("0. exit\n");
    printf("1. add node into the list at last position\n");
    printf("2. add node into the list at first position\n");
    printf("3. add node into the list at specific position\n");
    printf("4. delete node from the list which is at first position\n");
    printf("5. delete node from the list which is at last position\n");
    printf("6. delete node from the list which is at specific position\n");
    printf("7. display the list\n");

    printf("enter the choice: ");
    scanf("%d", &choice);

    return choice;
}

enum menu_options{ EXIT, ADDLAST, ADDFIRST, ADDATPOS, DELFIRST, DELLAST, DELATPOS, DISP };

int main(void)
{
    int pos;
    int data;

    //menu driven program
    while( 1 )
    {
        int choice = menu();

        switch(choice)
        {
            case EXIT:
                exit(0);

            case ADDLAST:
                printf("enter the data: ");
                scanf("%d", &data);
                add_node_into_list_at_last_position(data);
                break;

            case ADDFIRST:
                printf("enter the data: ");
                scanf("%d", &data);
                add_node_into_list_at_first_position(data);
                break;

            case ADDATPOS:

                while( 1 )
                {
                    //step-1: accept position from the user
                    printf("enter the position: ");
                    scanf("%d", &pos);
                    //validate the position
                    if( pos >= 1 && pos <= count_nodes() + 1 )
                        break;
                    
                    printf("invalid position !!!\n");
                }

                printf("enter the data: ");
                scanf("%d", &data);
                add_node_into_list_at_specific_position(pos, data);
                break;

            case DELFIRST:
                delete_node_at_first_position();
                break;

            case DELLAST:
                delete_node_at_last_position();
                break;

            case DELATPOS:
                while( 1 )
                {
                    //step-1: accept position from the user
                    printf("enter the position: ");
                    scanf("%d", &pos);
                    //validate the position
                    if( pos >= 1 && pos <= count_nodes() )
                        break;
                    
                    printf("invalid position !!!\n");
                }

                delete_node_at_specific_position(pos);
                break;

            case DISP:
                display_list();
                break;
        }
    }
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

void add_node_into_list_at_last_position(int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty -- attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;
    }
    else//step-3: if list is not empty
    {
        //start traversal from first node
        node_t *trav = head;

        //traverse the list till last node
        while( trav->next != NULL ){
            trav = trav->next;//move trav pointer towards its next node
        }

        /* attach newly created node to the last node i.e. store an addr newly created
        node into next part of last node */
        trav->next = newnode;
    }
}

void add_node_into_list_at_first_position(int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty -- attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;
    }
    else//step-3: if list is not empty
    {
        //store an addr cur first node into the next part of newly created node
        newnode->next = head;
        //attach newly craeted node the head
        head = newnode;
    }
}

int count_nodes(void)
{
    int cnt = 0;

    //if list is not empty
    if( head != NULL )
    {
        node_t *trav = head;
        while( trav != NULL ){
            cnt++;
            trav = trav->next;
        }
    }

    return cnt;
}

void display_list(void)
{
    //if list is not empty
    if( head != NULL )
    {
        //start traversal from the first node
        node_t *trav = head;
        printf("no. of nodes in a list are: %d\n", count_nodes());
        printf("list is: head -> ");
        //traverse the list till last node (including it)
        while( trav != NULL ){
            printf("%d -> ", trav->data);//display data part of each node
            trav = trav->next;//move trav pointer towards its next node
        }
        printf("null\n");
    }
    else
        printf("list is empty !!!\n");
}

//valid positions are from --> 1 to count_nodes+1
void add_node_into_list_at_specific_position(int pos, int data)
{
    if( pos == 1 )//if pos is the first position
        add_node_into_list_at_first_position(data);
    else if( pos == count_nodes() +1 )//if pos is the last position
        add_node_into_list_at_last_position(data);
    else//if pos is inbetween position
    {
        //create a newnode
        node_t *newnode = create_node(data);
        //start traversal from first node
        node_t *trav = head;
        int i=1;
        
       //traverse the list till (pos-1)th node
        while( i < pos-1 ){
            i++;
            trav = trav->next;
        }

        //store an addr cur (pos)th node into the next part newly created node
        newnode->next = trav->next;
        //store an addr of newly created node into next part of (pos-1)th node
        trav->next = newnode;
    }

}

void delete_node_at_first_position(void)
{
    //if list is not empty
    if( head != NULL )
    {
        //if list contains only one node
        if( head->next == NULL )
        {
            //delete the node and make head as NULL
            free(head);
            head = NULL;
        }
        else{//if list contains more than one node
            //store an addr of cur first node into temp
            node_t *temp = head;
            //store an addr of cur second node into the head
            head = head->next;
            free(temp);
        }
    }
    else
        printf("list is empty !!!\n");
}

void delete_node_at_last_position(void)
{
    //if list is not empty
    if( head != NULL )
    {
        //if list contains only one node
        if( head->next == NULL )
        {
            //delete the node and make head as NULL
            free(head);
            head = NULL;
        }
        else{//if list contains more than one node
            node_t *trav = head;
            //traverse the list till second last node
            while( trav->next->next != NULL )
                trav = trav->next;

            //delete the last node
            free(trav->next);//free(6000);
            //make next part of cur second last node as NULL, so that it will become a last node
            trav->next = NULL;
        }
    }
    else
        printf("list is empty !!!\n");

}

void delete_node_at_specific_position(int pos)
{
    if( pos == 1 )//if pos is the first position
        delete_node_at_first_position();
    else if( pos == count_nodes() )//if pos is the last position
        delete_node_at_last_position();
    else{//if pos is inbetween position
        int i=1;
        node_t *trav = head, *temp = NULL;
        //traverse the list till (pos-1)th node
        while( i < pos-1 ){
            i++;
            trav = trav->next;
        }
        //store addr of node which is to be deleted in a temp
        temp =  trav->next;
        //store an addr of cur (pos+1)th node into next part of (pos-1)th node
        trav->next = trav->next->next;
        free(temp);
    }
}






