#include "fichier.hpp"
#include <sstream>
#include<string>
#include <fstream>
#include <iostream>
using namespace std;

Fichier::Fichier() : l(0), L(0) {}

void Fichier::lireFichier(const string& chemin)
{
    //récupérer la largeur et longueur de la matrice
     ifstream fichier(chemin); //prendra le chemin entré par l'utilisateur dans le main
     if (fichier)
     {
         //pour vérifier que le fichier est ouvert
         string ligne;
         int largeur;
         int longueur;
         if (getline(fichier, ligne)) {

             stringstream ss(ligne);
             ss >> largeur >> longueur;

             //mettre 1er caractère sur la largeur et le second sur la longueur
             this -> setL(largeur);
             this -> setl(longueur);

             cout << "Largeur de la matrice : " << this ->getL() << endl;
             cout << "Longueur de la matrice : " << this-> getl() << endl;
         }
     }

     else if (!fichier)
     {
         cout << "ERREUR : le fichier ne s'est pas ouvert" <<endl;
     }

 }

 void Fichier::creerFichier() {
 }
