#include <stdio.h>
#include <stdlib.h>
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
void triRapid(untableau tab, int first, int last) {
    int pivot, i, j;
    char tmp[12];
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (strcmp(tab[i],tab[pivot])>0 && i<last)
                i++;
            
                
            while(strcmp(tab[j],tab[pivot])<0)
                j--;
            
                
            if(i < j) {
                strcpy(tmp,tab[j]);
                strcpy(tab[j],tab[i]);
                strcpy(tab[i],tmp);
            }
        }
        strcpy(tmp,tab[j]);
        strcpy(tab[j],tab[pivot]);
        strcpy(tab[pivot],tmp);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
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
    
    triRapid(tab, 0, MAX - 1);
    
    printf("\n Tableau trié     : \n");
    for(i = 0; i < MAX; i++)  {
        printf(" %s\n", tab[i]);
    }
    printf("\n");
    return 0;
}