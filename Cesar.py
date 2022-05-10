import random



def motToDico(mot):
    dictionnaire=[]
    for i in range(len(mot)):
        dictionnaire.append(mot[i])
    return dictionnaire


def charToInt(dictionnaire):
    for i in range(len(dictionnaire)):
        #Ord permet de convertir un caractère en son nombre ascii/Inverse chr()
        dictionnaire[i]=ord(dictionnaire[i])
    return dictionnaire

def chiffrage(dictionnaire,cle):
    chifree=[]
    temp=None
    """
    Double boucle :
    La première pour faire tous les mots 
    La deuxième si le nombre ascii dépasse 122 
    """
    initialisation = 0
    z=0
    for i in range(len(dictionnaire)):
        while (z<cle):
            if (initialisation==0):
                temp=dictionnaire[i]
                initialisation+=1
            print(dictionnaire[i])
            print(temp)
            if (temp != 123):
                temp+=1
                
                z+=1
            else:
                temp=97
                
            
        chifree.append(temp)
        initialisation=0
        z=0
    return chifree

def intToChar(chifree) :
    for i in range(len(chifree)):
        #Chr permet de convertir un int en char ascii
        chifree[i]=(chr(chifree[i]))
    return chifree

mot= input("Quel est le mot à chiffrer : ")
#Mettre en minuscule pour éviter des problèmes dans la table Ascii/Peut-être changer plus tard
mot = mot.lower()
print(mot)
#Création du dictionnaire de mot
cle = random.randint(1, 24)
dictionnaire = []
chifree = []
aaa=[]
print(cle)
dictionnaire= motToDico(mot)
print(dictionnaire)
dictionnaire=charToInt(dictionnaire)
print(dictionnaire)
chifree=chiffrage(dictionnaire, cle)
print(chifree)
aaa=intToChar(chifree)
print(aaa)

