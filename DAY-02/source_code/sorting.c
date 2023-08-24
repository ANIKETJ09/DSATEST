//implementation of sorting algorithms:
#include<stdio.h>
#define SIZE 6

#define SWAP(a, b) { int temp = a; a=b; b=temp; }


//function declarations
void display_array_elements(int arr[]);
void selection_sort(int arr[]);
void bubble_sort(int arr[]);
void insertion_sort(int arr[]);

//entry point function
int main(void)
{
    //int arr[SIZE] = {30,20,60,50,10,40};
    int arr[SIZE] = {10,20,30,40,50,60};
    //int arr[SIZE] = {30,90,20,70,60,100,50,80,10,40};

    printf("bfore sorting array ele's are: "); display_array_elements(arr);
    
    //selection_sort(arr);
    //bubble_sort(arr);
    insertion_sort(arr);

    printf("after sorting array ele's are: "); display_array_elements(arr);

    return 0;
}

//function definitions
void display_array_elements(int arr[])
{
    int index;
    
    for( index = 0 ; index < SIZE ; index++ ){
        printf("%4d", arr[ index ]);
    }
    printf("\n");
}

void selection_sort(int arr[])
{
    int iterations = 0;
    int comparisons = 0;
    int sel_pos;
    int pos;

    for( sel_pos = 0 ; sel_pos < SIZE-1 ; sel_pos++ ){//outer for is for iterations
        iterations++;
        for( pos = sel_pos + 1 ; pos < SIZE ; pos++ ){//inner for loop for positions
            //if ele which is sel_pos found greater than ele at pos - swap them
            comparisons++;
            if( arr[ sel_pos ] > arr[ pos ] )
                SWAP(arr[ sel_pos ], arr[ pos ] );
        }
    }

    printf("no. of iterations are: %d\n", iterations);
    printf("no. of comparisons are: %d\n", comparisons);
}

//efficient implementation of bubble sort by using logic of flag
void bubble_sort(int arr[])
{
    int iterations = 0;
    int comparisons = 0;
    int pos;
    int it;
    int flag = 1;

    for( it  = 0 ; it < SIZE-1 && flag == 1 ; it++ ){//outer for loop is for iterations
        iterations++;
        flag=0;
        for( pos = 0 ; pos < SIZE-1-it ; pos++ ){
            comparisons++;
            //if( prev pos ele > its next pos ele ) i.e. if ele's are not in order
            //10 20 30 40 50 60 - flag = 0
            if( arr[ pos ] > arr[ pos+1 ] )
            {
                SWAP(arr[ pos ], arr[ pos+1 ] );
                flag=1;
            }
        }
    }

    printf("no. of iterations are: %d\n", iterations);
    printf("no. of comparisons are: %d\n", comparisons);
}

/*
//basic bubble sort algorithm
void bubble_sort(int arr[])
{
    int iterations = 0;
    int comparisons = 0;
    int pos;
    int it;

    for( it  = 0 ; it < SIZE-1 ; it++ ){//outer for loop is for iterations
        iterations++;
        for( pos = 0 ; pos < SIZE-1-it ; pos++ ){
            comparisons++;
            //if( prev pos ele > its next pos ele ) i.e. if ele's are not in order
            if( arr[ pos ] > arr[ pos+1 ] )
            {
                SWAP(arr[ pos ], arr[ pos+1 ] );
            }
            
        }
    }

    printf("no. of iterations are: %d\n", iterations);
    printf("no. of comparisons are: %d\n", comparisons);
}
*/


void insertion_sort(int arr[])
{
    int i;
    int iterations=0;
    int while_cnt=0;

    for( i = 1 ; i < SIZE ; i++ ){
        iterations++;
        int key = arr[ i ];
        int j = i-1;

        while( j >= 0 && key < arr[ j ] ){
            while_cnt++;
            arr[ j+1 ] = arr[ j ];//shift ele towards its right bu 1 pos
            j--;
        }
        //insert key at its appropriate pos
        arr[ j+1 ] = key;
    }

    printf("no. of iterations are: %d\n", iterations);
    printf("no. of times control comes inside while loop: %d\n", while_cnt);
}



















