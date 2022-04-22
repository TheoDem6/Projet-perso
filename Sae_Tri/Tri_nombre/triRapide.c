#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef int untableau[MAX];

void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void triRapid(int tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}
int main() {
    int  i;
    untableau tab = {99, 47, 54, 12, 25, 39, 18, 26, 81, 39} ;
    printf("\n Tableau non trié : ");
    for(i = 0; i < MAX; i++)  {
        printf(" %4d", tab[i]);
    }
    
    triRapid(tab, 0, MAX - 1);
    
    printf("\n Tableau trié     : ");
    for(i = 0; i < MAX; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    return 0;
}