#include <stdlib.h>
#include <stdio.h>
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

void tri_cara(untableau tab){
    char tmp[12];
    int i,j;
    for (i=0;i<MAX-1;i++){
        for (j=0;j<MAX-i-1;j++){
            if (strcmp(tab[j],tab[j+1])<0){
                strcpy(tmp,tab[j]);
                strcpy(tab[j],tab[j+1]);
                strcpy(tab[j+1],tmp);
                
                
            }
        }
    }
}
int main(){
    untableau tab={0};
    int i;
    i=0;
    srand(time(NULL));
    printf("\n\t Tri bulle decroissant\n");
    alea(tab);
    printf("\t tableau avant le tri \n");
    for (i=0; i < MAX; ++i){
        printf("%s\n", tab[i]);
    }
    tri_cara(tab);
    printf("\n\t tableau apres le tri\n");
    for (i=0; i < MAX; ++i){
        printf("%s\n", tab[i]);
    }
    return EXIT_SUCCESS;
}