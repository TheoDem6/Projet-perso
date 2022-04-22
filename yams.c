/**
 * \file main.c
 * \brief Jeux du yams.
 * \author Théo Demany J1
 * \date 21 Novembre 2021
 *
 * 
 *
 */
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
//Définition des tableaux//
/**
 * \def N
 * \brief constante pour la taille du tableau des scores
 * \typedef untableau
 */
#define N 13
typedef int untableau[N];
/**
 * 
 * \def N
 * \brief constante pour la taille du tableau dés dés
 * \typedef untableaudes
 */
#define D 5
typedef int untableaudes[D];
/**
 * \def N
 * \brief constante pour la taille du tableau des scores totaux
 * \typedef tabtotal
 */
#define G 2
typedef int tabtotal[G];
//constante//
/**
 * @brief constante pour le nombre de tour max
 * \def NB_TOUR_MAX
 * 
 */
const int NB_TOUR_MAX=12;
/**
 * @brief constante pour le nombre de joueur
 * \def NB_JOUEUR
 * 
 */
const int NB_JOUEUR=2;
//liste des procédures//
void afficherTab(untableau tabj1,untableau tabj2,tabtotal j1,tabtotal j2,char nomj1[20],char nomj2[20]);
//procédure qui prend en paramètre le tableau des 2 joueurs 
//et selon le joueur courant affiche le tableau du jouer 1 ou 2
void alea(untableaudes tabDes);
//procédure qui tire aléatoirement 5 dés 
//La procédure parcours le tableau et pour chaque nombre qui est égal à 0 retire aléatoirement pour cette case
//qui place les dés dans le tableau tabDes
void validationDes(untableaudes tabDes,int numDes); //<-- Pas besoin de cette procédure, déjà fait dans le programme principale
//procédure qui demande aux joueurs quels dés il ne veut pas garder
//par exemple s'il ne veut pas garder le premiers dés il met 1 qui vas remplacer la première valeur du tableau de dés par un 0 
void scoreTotal(int *scoreJ1,int *scoreJ2,untableau tabJ1, untableau tabJ2,tabtotal j1, tabtotal j2);
//procédure qui prend le score et le tableau des 2 joueurs
//il calcul le score des 2 joueurs en prenant les points de tous le tableau en l'ajoutant dans le score
//il ajoute si il y a le bonus de +35 si les 6 premières valeurs sont supèrieurs à 62
//affichage du total supèrieur et infèrieur
//Compare les 2 scores et indique qui est le gagnant

//Liste des fonctions//
int pointsCombi(untableaudes tabDes,untableau tabJ,int combinaison);
//fonction qui selon la combinaison du joueur vas calculer le score des points
//par exemple s'il veut entrer dans son tableau dans la case pour les 3(la troisième case du tableau)
//->ça vas prendre le nombres de 3 dans ses dés, les calculer et retourner le score que ça fait
//et ceci pour toutes les combinaisons
//avec un switch case 
int demanderCombinaison(untableau tabJ,untableaudes tabDes);
//procédure qui demande à l'utilisateur la combinaison qu'il veut valider, et transmet sur une autre fonction
//exemple s'il rentre 1 ça vas être dans la première case pour l'ensemble des as
//exemple s'il rentre 9 ça vas être dans la neuvième case pour la full house
//touties les cases sont initialisées à -1 donc si l'utilisateur demande une case déjà rempli ça lui redemande quel case il veut
int calculNombreDePoint(int choix,untableaudes tabDes);
//Calcul du nombre de points selon la combinaison
//Avec un switch case
int carre(untableaudes tabDes);
int brelan(untableaudes tabDes);
bool pair(untableaudes tabDes);
bool petiteSuite(untableaudes tabDes);
bool grandesuite(untableaudes tabDes);
void afficherDes(untableau tabDes);


/**
 * \fn main()
 * \brief Programme principal du Yams
 * 
 * \return EXIT_Success
 */
int main(){
    //Le temps
    srand(time(NULL));
    //les noms des joueurs//
    char nomj1[20],nomj2[20];
    //les variables//
    int tourCourant,joueurCourant,initialisationDes,initialisationTab;
    int nbEssaiesRestant,nbDesaRelancer,des,numDes;
    int scoreJ1,scoreJ2,choix,nombreDePoint;
    //Les tableaux//
    untableau tabj1={};
    untableau tabj2={};
    untableaudes tabDes={};
    tabtotal j1={};
    tabtotal j2={};
    //Debut du programme//
    printf("Quel est le nom du joueur 1  :\n");
    scanf("%s",nomj1);
    printf("Quel est le nom du joueur 2  :\n");
    scanf("%s",nomj2);
    //Initalisation des tables à -1
    for (initialisationTab=0;initialisationTab<NB_TOUR_MAX;initialisationTab++){
        tabj1[initialisationTab]=-1;
        tabj2[initialisationTab]=-1;
    }
    //Boucle pour faire 13 tours
    for (tourCourant=0;tourCourant<NB_TOUR_MAX;tourCourant++){
        //Boucle pour que chaque joueur joue
        for (joueurCourant=0;joueurCourant<NB_JOUEUR;joueurCourant++){
            choix=0;
            nombreDePoint=0;
            //Initialisation des des à 0
            for (initialisationDes=0;initialisationDes<5;initialisationDes++){
                tabDes[initialisationDes]=0;
            }
            afficherTab(tabj1,tabj2,j1,j2,nomj1,nomj2); 
            if (joueurCourant==0){
                printf("C'est au tour de %s\n",nomj1);
            }
            else{
                printf("C'est au tour de %s\n",nomj2);
            }
            nbEssaiesRestant=3;
            nbDesaRelancer=123;
            while((nbEssaiesRestant!=0)&&(nbDesaRelancer!=0)){ 
                printf("Il vous reste %d essai(s) \n",nbEssaiesRestant);
                alea(tabDes);
                printf("Combien de dés voulez-vous relancer ?, choisissez un nombre entre 0 et 5 \n");
                scanf("%d",&nbDesaRelancer);
                printf("%d",nbDesaRelancer);
                while (nbDesaRelancer<0 && nbDesaRelancer>6){
                    printf("Choix non valide, choisissez un dés entre 0 et 5\n");
                    scanf("%d",&nbDesaRelancer);
                    
                }
                if (nbDesaRelancer !=0){
                        for (des=0;des<nbDesaRelancer;des++){
                            printf("Quel dés à relancer ? (Choisissez un nombre entre 0 et 5) \n");
                            scanf("%d",&numDes);
                            while(numDes<0&&numDes>5){
                                printf("Choix non valide, choisissez un dés entre 0 et 5 \n");
                                scanf("%d",&numDes);
                                printf("%d",numDes);
                            }
                            tabDes[numDes]=0;
                            printf("%d\n",tabDes[numDes]);
                        }
                }
                
                nbEssaiesRestant--;

            }
            if (joueurCourant==0){
                afficherDes(tabDes);
                choix=demanderCombinaison(tabj1,tabDes);
                nombreDePoint =calculNombreDePoint(choix,tabDes);
                tabj1[choix]=nombreDePoint;
            }
            else{
                afficherDes(tabDes);
                choix=demanderCombinaison(tabj2,tabDes);
                nombreDePoint=calculNombreDePoint(choix,tabDes);
                tabj2[choix]=nombreDePoint;
            }
        }
    }
    scoreTotal(&scoreJ1,&scoreJ2,tabj1,tabj2,j1,j2);
    if (scoreJ1>scoreJ2){
        printf("Le joueur 1 est le gagnant\n");
    }
    else if (scoreJ1<scoreJ2){
        printf("Le joueur 2 est le gagnant\n");
    }
    else{
        printf("Egalité\n");
    }


    
}
/**
 * \fn afficherTab(untableau tabj1,untableau tabj2)
 * \brief Procédure qui affiche le tableau de scores des joueurs
 * \param tabj1 score du joueur 1
 * \param tabj2 score du joueur 2
 * 
 * 
 */ 
void afficherTab(untableau tabj1,untableau tabj2,tabtotal j1, tabtotal j2,char nomj1[20],char nomj2[20]){
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|                                         TABLEAU DE SCORE                           |\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|score               |             %s           |               %s               |\n",nomj1,nomj2);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|1[TOTAL DE 1]⚀      |             %d              |            %d                   |\n",tabj1[0],tabj2[0]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|2[TOTAL DE 2]⚁      |             %d              |            %d                   |\n",tabj1[1],tabj2[1]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|3[TOTAL DE 3]⚂      |             %d              |            %d                   |\n",tabj1[2],tabj2[2]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|4[TOTAL DE 4]⚃      |             %d              |            %d                   |\n",tabj1[3],tabj2[3]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|5[TOTAL DE 5]⚄      |             %d              |            %d                   |\n",tabj1[4],tabj2[4]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|6[TOTAL DE 6]⚅      |             %d              |            %d                   |\n",tabj1[5],tabj2[5]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Bonus si > à 62[35] |             %d              |              %d                   |\n",j1[0],j2[0]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Total supèrieur     |             %d              |              %d                   |\n",j1[1],j2[2]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Brelan [Total]      |             %d              |            %d                   |\n",tabj1[6],tabj2[6]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Carré [Total]       |             %d              |            %d                   |\n",tabj1[7],tabj2[7]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Full House          |             %d              |            %d                   |\n",tabj1[8],tabj2[8]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Petite suite [25]   |             %d              |            %d                   |\n",tabj1[9],tabj2[9]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Grande suite [30]   |             %d              |            %d                   |\n",tabj1[10],tabj2[10]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Yams [50]           |             %d              |            %d                   |\n",tabj1[11],tabj2[11]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Chance [Total]      |             %d                |          %d                     |\n",tabj1[12],tabj2[12]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|Total infèrieur    |              %d                |          %d                     |\n",j1[3],j2[3]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------|\n");
    printf("| TOTAL              |             %d               |           %d                     |\n",j1[4],j2[4]);
    printf("|------------------------------------------------------------------------------------|\n");
    printf("|------------------------------------------------------------------------------------|\n");
    

}
/**
 * \fn alea(untableaudes tabDes)
 * \brief Procédure qui tire un nombre aléatoire entre 1 et 6
 * \param  tabDes tableau pour conserver les dés 
 */ 

void afficherDes(untableau tabDes){
    for (int i=0;i<D;i++){
        switch (tabDes[i])
        {
        case 1:
            printf("--------\n");
            printf("|       |\n");
            printf("|   °   |\n");
            printf("|       |\n");
            printf("--------\n");
            
            
            break;
        case 2:
            printf("---------\n");
            printf("| °     |\n");
            printf("|       |\n");
            printf("|     ° |\n");
            printf("---------\n");
            break;
        case 3:
            printf("---------\n");
            printf("| °     |\n");
            printf("|   °   |\n");
            printf("|     ° |\n");
            printf("---------\n");
            break;
        case 4:
            printf("---------\n");
            printf("| °    °|\n");
            printf("|       |\n");
            printf("| °    °|\n");
            printf("---------\n");
            break;
        case 5:
            printf("---------\n");
            printf("| °    °|\n");
            printf("|    °  |\n");
            printf("| °    °|\n");
            printf("---------\n");
            break;
        case 6:
            printf("---------\n");
            printf("| °    °|\n");
            printf("| °    °|\n");
            printf("| °    °|\n");
            printf("---------\n");
            break;
        
        default:
           
            break;
        }
    }
    
    
}


void alea(untableaudes tabDes){
    int nombre=0;
    int i;
    for (i=0;i<D ;i++){
        nombre=(rand()%6+1);
        if (tabDes[i]==0){
            tabDes[i]=nombre;
            

        }
        
    }
    printf("\n");
    for (i=0;i<D;i++){
        switch (tabDes[i])
        {
        case 1:
            printf("--------\n");
            printf("|       |\n");
            printf("|   °   |\n");
            printf("|       |\n");
            printf("--------\n");
            
            
            break;
        case 2:
            printf("---------\n");
            printf("| °     |\n");
            printf("|       |\n");
            printf("|     ° |\n");
            printf("---------\n");
            break;
        case 3:
            printf("---------\n");
            printf("| °     |\n");
            printf("|   °   |\n");
            printf("|     ° |\n");
            printf("---------\n");
            break;
        case 4:
            printf("---------\n");
            printf("| °    °|\n");
            printf("|       |\n");
            printf("| °    °|\n");
            printf("---------\n");
            break;
        case 5:
            printf("---------\n");
            printf("| °    °|\n");
            printf("|    °  |\n");
            printf("| °    °|\n");
            printf("---------\n");
            break;
        case 6:
            printf("---------\n");
            printf("| °    °|\n");
            printf("| °    °|\n");
            printf("| °    °|\n");
            printf("---------\n");
            break;
        
        default:
           
            break;
        }
    }
    
    
}


/**
 * \fn calculNombreDEPoint(int choix,untableaudes tabDes,int nombreDePoint)
 * \brief fonction qui calcul le nombre de points selon la combinaison 
 * \param  choix Choix de la combinaison
 * \param tabDes le tableau de dés pour voir si la combinaison est valable
 * \param nombreDePoint le nombre de point qu'on vas retourner 
 * \return le nombre de point de la combinaison et 0 s'il n'en avait pas
 * 
 *
 * 
 * 
 */ 


int calculNombreDePoint(int choix,untableaudes tabDes){
    int i,j,mem,yams;
    bool valable;
    int nombreDePoint;
    nombreDePoint=0;
    choix++;
    //Triage de mon tableau de dés
    for (i=0;i<D-1;i++){
        for (j=0;j<D-i-1;j++){
            if (tabDes[j]>tabDes[j+1]){
                mem=tabDes[j];
                tabDes[j]=tabDes[j+1];
                tabDes[j+1]=mem;
            }
        }

    }
    
    switch (choix){
        case 1:
            for (i=0;i<D;i++){
                if(tabDes[i]==1){
                    nombreDePoint=nombreDePoint+1;
                    printf("%d",nombreDePoint);
                    
                }
                
            }
            
                return nombreDePoint;
                    break;
        case 2:
            for (i=0;i<D;i++){
                if(tabDes[i]==2){
                    nombreDePoint=nombreDePoint+2;
                    printf("%d",nombreDePoint);
                }
                
            }
                return nombreDePoint;
                    break;
        case 3:
            for (i=0;i<D;i++){
                if(tabDes[i]==3){
                    nombreDePoint=nombreDePoint+3;
                    printf("%d",nombreDePoint);
                    
                }
            }
                return nombreDePoint;
                    break;
        case 4:
            for (i=0;i<D;i++){
                if(tabDes[i]==4){
                    nombreDePoint=nombreDePoint+4;
                    printf("%d",nombreDePoint);
                }
            }
                    return nombreDePoint;
                    break;
                    
                
            
            
            
        case 5:
            for (i=0;i<D;i++){
                if(tabDes[i]==5){
                    nombreDePoint=nombreDePoint+5;
                    printf("%d",nombreDePoint);
                    
                }
            }
                    return nombreDePoint;
                    break;
            
        case 6:
            for (i=0;i<D;i++){
                if(tabDes[i]==6){
                    nombreDePoint=nombreDePoint+6;
                    printf("%d",nombreDePoint);
                }
                

            }
                return nombreDePoint;
                    break;
        case 7:
            //Pour le brelan
            nombreDePoint=brelan(tabDes);
            return nombreDePoint;
            break;

        case 8:
            //Pour le carré
            nombreDePoint=carre( tabDes);
            return nombreDePoint;
            break;
            
            
        case 9:
            //pour le full house 
            //D'abord je regarde s'il y a une pair
            valable=pair(tabDes);
            // S'il y a une pair alors je regarde le brelan
            if (valable==true){
                nombreDePoint=brelan(tabDes);
            }
            //Et si le nombre de points est différents de 0 alors il y a un brelan et donc je retourne 25 points

            if (nombreDePoint!=0){
                nombreDePoint=25;
                return nombreDePoint;
            }
            else {
                return 0;
            }
            break;

        case 10 :
            //Pour la petite suite
                
            valable=petiteSuite(tabDes);
            if (valable==true){
                nombreDePoint=30;
                return nombreDePoint;
            }
            else {
                return 0;
            }
            break;
        case 11:
            //Pour la grande suite
                
            valable=grandesuite(tabDes);
            if (valable==true){
                nombreDePoint=40;
                return nombreDePoint;
            }
            else {
                return 0;
            }
            break;
        case 12:
            //Pour le Yams
                
            yams=0;
            for (i=0;i<D;i++){
                if (tabDes[i]==tabDes[i+1]){
                    yams++;
                }
            }
            if (yams==4){
                nombreDePoint=50;
                return nombreDePoint;
            }
            else{
                return 0;
            }
            break;
        case 13:
            //Pour le total
                
            for (i=0;i<D;i++){
                nombreDePoint=nombreDePoint+tabDes[i];
            }
            return nombreDePoint;
            break;
            
        default:
            return 0;
            break;
    }
    return nombreDePoint;
}

/**
 * \fn brelan(untableaudes tabDes)
 * \brief Fonction qui calcul s'il le brelan est valide ou non
 * \param tabDes le tableau des des
 * \return le nombre de point du brelan

 * 
 */ 

int brelan(untableaudes tabDes){
    untableaudes unTabDeDEs={};
    int i,combinaison,Pcombi;
    combinaison=0;
    Pcombi=0;
    for (i=0;i<N;i++){
        Pcombi=Pcombi+unTabDeDEs[i];
        if(unTabDeDEs[i]==unTabDeDEs[i+1]){
            combinaison++;

        }
    }
    if (combinaison==3){
        return Pcombi;

    }
    else{
        return 0;
    }
    
   
}
/**
 * \fn carre(untableaudes tabDes)
 * \brief Fonction qui calcul s'il le carre est valide ou non
 * \param tabDes le tableau des des
 * \return le nombre de point du carre

 * 
 */ 

int carre(untableaudes tabDes){
    untableaudes unTabDeDEs={};
    int i,combinaison,Pcombi;
    combinaison=0;
    Pcombi=0;
    for (i=0;i<D;i++){
        Pcombi=Pcombi+unTabDeDEs[i];
        if(unTabDeDEs[i]==unTabDeDEs[i+1]){
            combinaison++;

        }
    }
    if (combinaison==4){
        return Pcombi;

    }
    else{
        return 0;
    }
}
/**
 * \fn pair(untableaudes tabDes)
 * \brief Fonction qui calcul s'il la pair est valide ou non
 * \param tabDes le tableau des des
 * \return le nombre de point de la pair

 * 
 */ 

bool pair(untableaudes tabDes){
    untableaudes unTabDeDEs={};
    int i,combinaison,Pcombi;
    combinaison=0;
    Pcombi=0;
    for (i=0;i<N;i++){
        Pcombi=Pcombi+unTabDeDEs[i];
        if(unTabDeDEs[i]==unTabDeDEs[i+1]){
            combinaison++;

        }
    }
    if (combinaison==2){
        return true;

    }
    else{
        return false;
    }
}

//Fonction qui pour connaitre si les dés ont une petite suite ou non
/**
 * 
 * 
 * \fn bool petiteSuite(untableaudes tabDes)
 * \brief fonction pour voir s'il y a une petite suite
 * \param tabDes : le tableau de dés 
 * \return true s'il y a
 * \return false s'il n'y a pas
 */
bool petiteSuite(untableaudes tabDes){
    int i,Pcombi;
    Pcombi=0;
    for (i=0;i<D;i++){
        if (tabDes[i]+1==tabDes[i+1]){
            Pcombi++;
            
        }
    }
    if (Pcombi>=4){
        return true;
    }
    else{
        return false;
    }
}
//Fonction qui pour connaitre si les dés ont une grande suite ou non

/**
 * 
 * \brief fonction pour voir s'il y a une petite suite
 * \fn bool grandesuite(untableaudes tabDes)
 * \param tabDes : le tableau de dés 
 * \return true s'il y a
 * \return false s'il n'y a pas
 */
bool grandesuite(untableaudes tabDes){
    int i,Pcombi;
    Pcombi=0;
    for (i=0;i<D;i++){
        if (tabDes[i]+1==tabDes[i+1]){
            Pcombi++;
            
        }
    }
    if (Pcombi>=5){
        return true;
    }
    else{
        return false;
    }
}



/**
 * \fn demanderCombinaison(untableau tabJ,untableaudes tabDes)
 * \brief Fonction qui vérifie si la combinaison est valide ou pas(si elle est déjà été pris )
 * \param tabJ le tableau de joueur
 * \param tabDes le tableau de des
 * \return la combinaison du joueurj1[2]=j1[0]+j1[1];

 * 
 */ 

int demanderCombinaison(untableau tabJ,untableaudes tabDes){
    int combinaison;
    printf("Quel combinaison avez-vous eu ? as=1 deux = 2...Brelan=7...Yams=12..Chance = 13\n");
    scanf("%d",&combinaison);
    while(tabJ[combinaison]!=-1&&(tabJ[combinaison]<0&&tabJ[combinaison>13])){
        printf("Cette case est déjà remplie, choissiez en une autre ou choisissez un nombre entre 0 et 13 \n");
        scanf("%d",&combinaison);
    }
    
    combinaison--;
    
    
    return combinaison;


}
/**
 * \fn calculNombreDEPoint(int choix,untablprintf("La total du joueur 1 est : %d",*scoreJ1);eaudes tabDes,int nombreDePoint)
 * \brief fonction qui calcul le nombre de points selon la combinaison 
 * \param  choix Choix de la combinaison
 * \param tabDes le tableau de dés pour voir si la combinaison est valable
 * \param nombreDePoint le nombre de point qu'on vas retourner 
 * \return le nombre de point de la combinaison et 0 s'il n'en avait pas
 * 
 *
 * 
 * 
 */ 

void scoreTotal(int *scoreJ1,int *scoreJ2,untableau tabJ1, untableau tabJ2,tabtotal j1,tabtotal j2){
    ///Calcul des scores supèrieur 
    int i,sommej1,sommej2;
    sommej1=0;
    sommej2=0;
    for (i=0;i<5;i++){
        sommej1=sommej1+tabJ1[i];
        sommej2=sommej2+tabJ2[i];
    }
    //calcul du bonus
    if (sommej1>62){
        sommej1=sommej1+35;
        printf("La somme du joueur 1 est : %d",sommej1);

    }
    if (sommej2>62){
        sommej2=sommej2+35;
        
        printf("La somme du joueur 2 est : %d",sommej2);
    }
    //Calcul du total supérieur
    for (i=0;i<6;i++){
        j1[0]=j1[0]+tabJ1[i];
    }
    for (i=0;i<6;i++){
        j2[0]=j2[0]+tabJ2[i];
    }
    ///Calcul du total supèrieur
    for (i=6;i<N;i++){
        j1[1]=j1[1]+tabJ1[i];
    }
    for (i=6;i<N;i++){
        j2[1]=j2[1]+tabJ2[i];
        
    }
    ///Score total
    *scoreJ1=j1[0]+j1[1];
    printf("La total du joueur 1 est : %d",*scoreJ1);
    *scoreJ2=j2[0]+j2[1];
    printf("La total du joueur 1 est : %d",*scoreJ2);
}



