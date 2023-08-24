#include<stdio.h>
#include<stdio.h>

#define SIZE 10

int comparisons = 0;

void display_array_elements(int arr[]);//arr - it is a pointer to 1-d array
int linear_search(int arr[], int key);
int binary_search(int arr[], int key);



int main(void)
{
    int key;
    //int arr[SIZE] = {20,30,50,10,100,90,80,70,60,40}; 
    int arr[SIZE] = { 10,20,30,40,50,60,70,80,90,100 }; 

    display_array_elements(arr);

    printf("enter the key: ");
    scanf("%d", &key);

    //if( linear_search(arr, key) )

    if( binary_search(arr, key) )
        printf("%d is found, no. of comparisons are: %d\n", key, comparisons);
    else 
        printf("%d is not found, no. of comparisons are: %d\n", key, comparisons);

    return 0;
}

void display_array_elements(int arr[])
{
    int index;
    printf("array ele's are: ");
    for( index = 0 ; index < SIZE ; index++ )
        printf("%4d", arr[index]);

    printf("\n");

}

int linear_search(int arr[], int key)
{
    int index;
    comparisons=0;

    for( index = 0 ; index < SIZE ; index++ )
    {
        comparisons++;
        if( key == arr[ index ] )
            return 1;//return true -> key is found
    }
    return 0;//return false -> key is not found
}

/* same function with comments:
int binary_search(int arr[], int key)
{ 
    int left = 0;
    int right = SIZE-1;
    comparisons=0;

    while( left <= right )//if( left > right ) -> break the loop
    {
        //calculate mid position -> array is getting divided into 2 subarrays
        int mid = (left+right)/2;

        //compare value of key with ele which is at mid pos
        comparisons++;
        if( key == arr[ mid ] )
            return 1;//return true --> key is found
        
        //either we will search key into the left subarray or into the right subarray
        if( key < arr[ mid ] )
            right = mid-1;//search key into the left subarray
        else
            left = mid+1;//search key into the right subarray
    }
    return 0;//return false --> key is not found
}
*/

int binary_search(int arr[], int key)
{ 
    int left = 0;
    int right = SIZE-1;
    comparisons=0;

    while( left <= right )
    {
        int mid = (left+right)/2;

        comparisons++;
        if( key == arr[ mid ] )
            return 1;

        if( key < arr[ mid ] )
            right = mid-1;
        else
            left = mid+1;
    }
    return 0;
}















