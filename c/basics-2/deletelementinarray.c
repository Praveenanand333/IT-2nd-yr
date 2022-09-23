#include <stdio.h>   
   
void deleteElement (int *arr, int num, int pos)  
{  
    int i;   
    for (i = pos-1; i < num - 1; i++)  
    {  
        arr[i] = arr[i+1];   
    }  
}  
    
void disp( int arr[], int num)  
{  
    int i;   
    for ( i = 0; i < num; i++)  
    {  
        printf( "\n arr[%d] = %d", i, arr[i]);  
    }  
}  
  
void main ()  
{  
    int arr[100];  
    int i, num, pos, result;  
    printf (" Enter the size of the array: ");  
    scanf (" %d", &num);      
    printf (" \n Enter the %d elements in an array: \n", num);  
    for (i = 0; i < num; i++)  
    {  
        printf (" arr[%d] = ", i);  
        scanf (" %d", &arr[i]);  
    }    
    printf (" Enter the position of the element you want to delete from an array: ");  
    scanf (" %d", &pos);   
    if (pos <= num && pos > 0)  
    {  
        printf (" Array before deletion: \n");   
        disp (arr, num);   
        deleteElement(arr, num, pos);  
          
        printf (" \n Array after deletion: \n");  
        disp( arr, num-1);  
    }     
}  
