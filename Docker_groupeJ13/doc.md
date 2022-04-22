Voici la doc de la SAE-1.03 sujet 3 : Génération de données fictives

## Données
Pour les données : nom/prenomF/prenomH/profession...
Vous pouvez ajouter/enlever. Mais évitez les accents ça donne des problèmes lors de l'affiche des données
## script.php
Elle se présente sous cette forme :
genre|nom|prénom|mail|adresse|date|heure|code GUIP|mdp|adresse et ville|profession|entreprise
Pour modifier/ajouter des données il sufit de modifier script.php et de faire un echo suivi d'un ";" pour espacer et faciliter l'ajout dans le csv.

Attention il vas falloir ajouter des 
- chmod +x nom_fichier ou chmod +x * (pour tous les fichiers)
pour pouvoir les modifier
Et pour le docker si ça ne marche pas se mettre en "sudo" pour pouvoir faire marcher les dockers

Important, il faut importer l'image php avec la commande ci dessous
-   docker pull php-cli74
## start.Sh
Ce script permet d'une à la demande du nombre de donnés à l'utilisateur et de lancer le docker
(ce nombre va se stoquer dans un fichier facturation que nous pourrons récupérer)

Ensuite nous créons à partir de l'image php-cli74 une autre image différente pour pouvoir y ajouter des commandes (le dockerfile)
docker build -t data_creator_container .
-> le "." vas chercher dockerfile dans le dossier
-> le docker vas se nommer data_creator_containor
-> -t pour taguer une image

Et nous lançons le docker ()
docker run -v $(pwd):/app/ -e NB_DATA=$nbr data_creator_container
v $(pwd):/app/ -e NB_DATA=$nbr -> permet de placer nbr (le nombre de donnés que l'on veut) en paramètre de position et donc de pouvoir l'utiliser dans d'autre fichiers. Ce qui nous sera utile pour s'avoir le nombre de fois on veut que le script tourne

## DOCKERFILE
FROM bigpapoo/php-cli74
From montre de quel image on vas vouloir apporter des modifications ici php-cli74
(/!\On ne touche pas à l'image originale on utilise une "copie" et y apporter des modification qui ne seront modifier que quand on fait appelle à notre dockerfile)
RUN touch fic.txt
Avec le dockerfile nous créons le fichier fic.txt (là ou nous métrons les donnés après le script)
Et nous copier tous nos fichier dans le dossiers pour les mettres dans le dockers

-> Cela évite d'écrire plein de fois docker cp ... car nous avons beaucoup de fichier txt 
-> De plus cela évite si nous ajoutons des données à devoir tous remodifier.
WORKDIR /app
Workdir permet de montrer dans quel dossier du docker nous allons travailler
RUN chmod +x *
-> On donne accès aux droits à tous les fichiers (pour éviter des erreurs lors du passage du script)
ENTRYPOINT ["/app/test.sh"]
-> Et enfin le ENTRYPOINT pour directement au lancement du docker commencer le script

## test.sh
D'abord on regarde si le "nbr" existe, s'il n'existe pas on l'initalise à 1 pour que le programme tourne au moins 1 fois
Et ensuite la boucle de donnés que l'on veut
echo "" ... permet le retour à la ligne

## movetoCSV 
Permet de modifier le fichier txt en csv

## stop.sh
permet de supprimer tous les dockers à la fin
docker container prune

## Commande à taper pour avoir les données 

A faire avant tout et uniquement une seule fois :
-   docker pull php-cli74
Si les dockers ne marchent pas se mettre en sudo
Si les scripts ne veulent pas fonctionner faire
-chmod +x * (cette commande vas donner accès à tous les fichiers)
Important : Se mettre dans le dossier ou il y a les scripts et donnés (sinon ça ne marchera pas ...)
Pour lancer le script :
./start.sh
Attendre jusquà "Création des données finis"
le fichier de donnés "fic" se mettre directement dans le dossier ou vous êtes
Pour changer le fichier txt en csv (pas obligatoire à taper mais si vous voulez l'avoir en csv)
./movetoCSV.sh
Et enfin pour enlever tous les dockers
./stop.sh
->s'il y a demande de confirmation mettre "y"

Ce script à la fin vas nous donner 2 fichiers
-> 1 fichier csv avec toutes les données pour le client
-> 1 fichier txt avec le nombre de données que le client a voulu pour nous et pour pouvoir à la fin lui facturer


Script fait par Théo/Oscar/Kévin/Evan
Docker fait par Théo et Kévin
Documentation faite par Théo
Si il y a des choses que vous ne comprenez pas dans le script/docker/documentation demander à Théo Demany J1 :)
