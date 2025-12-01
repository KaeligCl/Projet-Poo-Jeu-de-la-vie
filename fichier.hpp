#pragma once
#include <tuple>
using namespace std;

class Fichier
{
private :
    int l; //longueur
    int L; //largeur
    tuple<int, int> CellulesVivantes; //avoir les coordonnées des cellules vivantes parmi les 8 voisines

public :
    Fichier();
    void setL(const int val) {L = val;}
    int getL() const {return L;}
    void setl(const int val) {l = val;}
    int getl() const {return l;}
    void creerFichier();
};
