#!/usr/bin/php
<?php
    //////////////////////////////////////////////////
    //                     GENRE                    //
    //////////////////////////////////////////////////
    $genre = rand(0,1);
    echo $genre;
    echo ";";



    //////////////////////////////////////////////////
    //                     NOM/PRENOM               //
    //////////////////////////////////////////////////

    if ($genre=0){
        $fichierprenom = file ("prenomH.txt");

    }else {
        $fichierprenom = file ("prenomF.txt");
    }
    $fichiernom = file("nom.txt");
    
    $inom = count($fichiernom);
    $iprenom = count ($fichierprenom);
    // initialise et prend un nombre aléatoire entre 0 et $inom:
    srand((double)microtime()*100);
    $inom = rand(0,$inom);
    $iprenom = rand(0,$iprenom);
    $inomadresse = rand(0,$inom);
    // affiche la ligne
    $nom = $fichiernom[$inom];
    $prenom = $fichierprenom[$iprenom];
    $nomadresse = $fichiernom[$inomadresse];
    //Permet d'enlever le retour à la ligne
    $prenom=preg_replace("#\n|\t|\r#","",$prenom);
    $nom=preg_replace("#\n|\t|\r#","",$nom);
    echo $nom;
    echo ";";
    echo $prenom;
    echo ";";
    



    //////////////////////////////////////////////////
    //                     MAIL                     //
    //////////////////////////////////////////////////
    $mail=[
        0=>'gmail.com',
        1=>'voila.fr',
        2=>'bbox.fr',
        3=>'orange.fr',
        4=>'yahoo.fr',
        5=>'hotmail.fr',
        6=>'ootlook.fr',
        7=>'laposte.fr',
        8=>'icloud.com',
        9=>'zoho.org',
        10=>'univ-rennes1.fr',
    ];
   
    $email = $prenom.".".$nom."@".$mail[rand(0,10)];
    echo $email;
    echo ";";
    



    //////////////////////////////////////////////////
    //                     ADRESSE                  //
    //////////////////////////////////////////////////
    
    $mot=[
        0=>'rue',
        1=>'avenue',
        2=>'place',
        3=>'residence',
        4=>'chemin',
        5=>'boulevard',
        6=>'impasse',
    ];
    $long=2;
    $cara="0123456789";
    $nombre_alea='';
    $adresse='';
    for ($i =0;$i<$long;$i++){
        $nombre_alea.=$cara[rand(0,strlen($cara)-1)];
    }
    $adresse.=$nombre_alea.', '.$mot[rand(0,6)].' de ';
    
    $adresse.=$nomadresse;
    $adresse=preg_replace("#\n|\t|\r#","",$adresse);
    echo $adresse ;
    echo ";";
    
    //////////////////////////////////////////////////
    //                     DATE                     //
    //////////////////////////////////////////////////
    
    $jour=date('d', strtotime( '-'.mt_Rand(0,31).' days')); //Un jour entre 0 et 31
    $mois= date('-m', strtotime( '+'.mt_Rand(0,12).' months')); // Un mois entre 0 et 12
    $annee=date('-Y', strtotime( '-'.mt_Rand(20,60).' years')); // Une année entre 20 et 60 ans avant aujourd'hui
    echo $jour.$mois.$annee;
    echo ";";
    
    

    //////////////////////////////////////////////////
    //                     HEURES                   //
    //////////////////////////////////////////////////
    $heure=(rand(0, 23) . ":");
    $minutes=(rand(0, 59) . ":");
    $seconde=(rand(0,59));
    echo $heure.$minutes.$seconde;
    echo ";";

    //////////////////////////////////////////////////
    //                     GUID                     //
    //////////////////////////////////////////////////
    $guid = bin2hex(openssl_random_pseudo_bytes(16));
    // openssl_random_pseudo_bytes(16)) -> Génère une chaîne de caractères pseudo-aléatoire d'octets, dont la longueur est spécifiée par le paramètre est 16;
    //bin2hex (())-> Convertit des données binaires en représentation hexadécimale
    echo $guid;
    echo ";";
    
    //////////////////////////////////////////////////
    //                     MOT DE PASSE             //
    //////////////////////////////////////////////////
    $caracteres = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ%*&?!';
    
    $longueur = rand(8, 16);
    $chaineAleatoire = '';
    for ($i = 0; $i < $longueur; $i++)
    {
        $chaineAleatoire .= $caracteres[rand(0, strlen($caracteres) - 1)];
    }
    echo $chaineAleatoire;
    echo ";";
    
    //////////////////////////////////////////////////
    //              VILLE/CODEPOSTAL                //
    //////////////////////////////////////////////////
    
    $fichierville=file("Ville_codepostal.txt");
    $iville=count($fichierville);
    $iville=rand(0,$iville);
    $ville=$fichierville[$iville];
    $ville=preg_replace("#\n|\t|\r#","",$ville);
    echo $ville;
    echo ";";

    //////////////////////////////////////////////////
    //              PROFESSION                      //
    //////////////////////////////////////////////////
    
    $fichierprof=file("profession.txt");
    $iprof=count($fichierprof);
    $iprof=rand(0,$iprof);
    $prof=$fichierprof[$iprof];
    $prof=preg_replace("#\n|\t|\r#","",$prof);
    echo $prof;
    echo ";";
    //////////////////////////////////////////////////
    //              NOM SOCIETE                     //
    //////////////////////////////////////////////////
    $fichiersoc=file("nom_societe.txt");
    $isoc=count($fichiersoc);
    $isoc=rand(0,$isoc);
    $soc=$fichiersoc[$isoc];
    $soc=preg_replace("#\n|\t|\r#","",$soc);
    echo $soc;
            
?>