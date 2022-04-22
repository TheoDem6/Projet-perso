#include <stdlib.h>
#include <stdio.h>
#define N 8

int main(){
    int tab[N] = {35, 47, 54, 12, 25, 12, 99, 28};
    int i, j, tmp;
    printf("\t Tri bulle croissant\n");
    printf("\t tableau avant le tri \n");
    for (i=0; i < N; ++i){
        printf("%4d", tab[i]);
    }
    for (i=0 ; i < N-1; i++){
        for (j=0 ; j < N-i-1; j++){
            if (tab[j] > tab[j+1]) {
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
    printf("\n\t tableau apres le tri\n");
    for (i=0; i < N; ++i){
        printf("%4d", tab[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
