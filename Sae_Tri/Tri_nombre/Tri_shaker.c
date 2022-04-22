
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef int untableau[MAX];
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;	
}

void cocktailSort(int list[]) 
{
    int bottom = 0;
    int top = MAX - 1;
    bool swapped = true; 
    int i;

    while(swapped == true) 
    {
        swapped = false; 
        for(i = bottom; i < top; i = i + 1)
        {
            if(list[i] > list[i + 1])  
            {
                swap(& list[i], & list[i + 1]); 
                swapped = true;
            }
        }
        
        top = top - 1; 
        for(i = top; i > bottom; i = i - 1)
        {
            if(list[i] < list[i - 1]) 
            {
                swap(& list[i], & list[i - 1]);
                swapped = true;
            }
        }
        
        bottom = bottom + 1;  
    }
}

int main() {
    int  i;
    untableau tab = {99, 47, 54, 12, 25, 39, 18, 26, 81, 39} ;
    printf("\n Tableau non trié : ");
    for(i = 0; i < MAX; i++)  {
        printf(" %4d", tab[i]);
    }
    
    cocktailSort(tab);
    
    printf("\n Tableau trié     : ");
    for(i = 0; i < MAX; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    return 0;
}