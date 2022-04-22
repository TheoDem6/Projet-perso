#!/bin/bash    

if [ -f fic.txt ]
then 
    rm fic.txt
fi

read -p "Combien de données voulez-vous ?" nbr
echo "Creation de $nbr données"
echo $nbr >> facturation.txt

docker build -t data_creator_container .
docker run -v $(pwd):/app/ -e NB_DATA=$nbr data_creator_container