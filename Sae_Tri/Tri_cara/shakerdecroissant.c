
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define MAX 150000
#define COLONNE 12
typedef char untableau[MAX][COLONNE];
void alea(untableau tab){
    for (int i=0; i<MAX; i++){
        int taille = 5+rand()%6;
        for(int j=0; j<taille; j++){
            char c=97+rand()%25;
            tab[i][j]=c;
            
        }
    }
    
}

void cocktailSort(untableau list) 
{
    int bottom = 0;
    int top = MAX - 1;
    bool swapped = true; 
    int i;
    char tmp[12];

    while(swapped == true) 
    {
        swapped = false; 
        for(i = bottom; i < top; i = i + 1)
        {
            
            if (strcmp(list[i],list[i+1])<0)
            {
                strcpy(tmp,list[i]);
                strcpy(list[i],list[i+1]);
                strcpy(list[i+1],tmp); 
                swapped = true;
            }
        }
        
        top = top - 1; 
        for(i = top; i > bottom; i = i - 1)
        {
            if(strcmp(list[i],list[i-1])>0) 
            {
                
                strcpy(tmp,list[i]);
                strcpy(list[i],list[i-1]);
                strcpy(list[i-1],tmp); 
                swapped = true;
            }
        }
        
        bottom = bottom + 1;  
    }
}

int main() {
    int  i;
    untableau tab = {0} ;
    srand(time(NULL));
    alea(tab);
    printf("\n Tableau non trié : \n");
    for(i = 0; i < MAX; i++)  {
        printf(" %s\n", tab[i]);
    }
    
    cocktailSort(tab);
    
    printf("\n Tableau trié     : \n");
    for(i = 0; i < MAX; i++)  {
        printf(" %s\n", tab[i]);
    }
    
    return 0;
}