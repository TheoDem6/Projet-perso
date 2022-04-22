#!/bin/bash

if  [[ -z "${NB_DATA}" ]]
then
    NB_DATA=1
fi

for ((c=0;c<$NB_DATA;c++))
do
    php script.php  >> fic.txt
    echo "" >> fic.txt
done
echo "Création des données finies !"
