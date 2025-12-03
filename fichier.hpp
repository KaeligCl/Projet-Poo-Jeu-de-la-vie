#pragma once
#include <utility>
#include <vector>
using namespace std;

class Fichier
{
private :
    int l; // lignes 
    int L; //colonnes
    grille data;

public :
    Fichier(){

        fstream MyFile("filename.txt");
        string rawData;
        getline(MyFile, rawData);
        MyFile.close();


        for (size_t i = 0; i < data.getHauteur(); i++) {
            for (size_t j = 0; j < data.getLargeur(); j++) {
                if (table[i][j] == 1)
                    data[i][j] = std::make_shared<celluleVivante>();
                else
                    data[i][j] = std::make_shared<celluleMorte>();
            }
        }
    }
    void setL(const int val) {L = val;}
    int getL() const {return L;}
    void setl(const int val) {l = val;}
    int getl() const {return l;}
    void creerFichier() const ;
};
