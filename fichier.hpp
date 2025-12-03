#pragma once
#include <utility>
#include <vector>
using namespace std;

class Fichier
{
private :
    int l; //longueur
    int L; //largeur
    vector<pair<int, int>> cellulesVivantes; //avoir les coordonnées des cellules vivantes parmi les 8 voisines
    vector<vector<int>> grille; //tableau de tableau dynamique pour stocker la grille sous forme de matrice

public :
    Fichier();
    void setL(const int val) {L = val;}
    int getL() const {return L;}
    void setl(const int val) {l = val;}
    int getl() const {return l;}
    void creerFichier() const ;
};
