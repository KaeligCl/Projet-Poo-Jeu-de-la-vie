#include "celluleMorte.hpp"
#include "celluleVivante.hpp"
#include "fichier.hpp"
#include "regles.hpp"
#include "grille.hpp"


int main(){

//Mit en commentaire pour pas gêner le reste
/*
    Fichier f;
    //regle r;
    cout << "Bienvenue dans le jeu de la vie"
    << "\nMettez le chemin d'acces de la matrice originelle (utilisez des /): " <<endl;
    string chemin;
    getline(cin, chemin);
    
    cout << "Entrer un nombre maximum d'iterations : " << endl;
    int nbrMaxItération;
    cin >> nbrMaxItération;
    while (nbrMaxItération <2) //si jamais l'utilisateur abuse
    {
        cout << "Veuillez entrer un nombre superieur à deux iterations : " <<endl;
        cin >> nbrMaxItération;
    }
    
    
    cout << "Mode de jeu choisi : mode console avec "
            "fichiers de sorties pour les premières iterations (1)" <<
                "Avec interface graphique (2) : "  <<endl;
    int choixMode;
    cin >> choixMode;
    
    if (choixMode == 1)
    {
        cout << "Vous avez choisi le mode console." << endl;
        f.lireFichier(chemin);
    }
    
    else if (choixMode == 2)
    {
        cout << "Vous avez choisi le mode interface graphique" << endl;
        f.lireFichier(chemin);
    }
    */

  
  RenderWindow window(VideoMode({800, 600}), "Grid Window");

    std::array<std::array<int, 15>, 20> myTable = {{
      {{1,0,1,0,0,1,0,1,1,0,0,1,0,1,0}},
      {{0,1,0,1,1,0,0,0,1,0,1,1,0,0,1}},
      {{1,1,0,0,0,1,1,0,0,1,0,1,0,0,0}},
      {{0,0,1,1,0,0,1,0,1,1,0,0,1,1,0}},
      {{1,0,0,1,0,1,0,0,0,1,1,0,1,0,1}},
      {{0,1,1,0,1,0,1,1,0,0,1,0,0,1,0}},
      {{1,0,1,1,0,0,1,0,0,1,0,1,1,0,0}},
      {{0,1,0,0,1,1,0,1,0,0,0,1,0,1,1}},
      {{1,0,1,0,0,0,1,1,1,0,1,0,0,1,0}},
      {{0,1,1,0,1,0,0,1,0,1,0,1,1,0,0}},
      {{1,0,1,1,0,1,0,0,1,0,0,1,0,0,1}},
      {{0,1,0,0,1,0,1,1,0,1,1,0,1,0,0}},
      {{1,0,1,0,0,1,0,1,1,0,0,1,0,1,0}},
      {{0,1,1,0,1,0,1,0,0,1,0,1,1,0,1}},
      {{1,0,0,1,0,1,0,0,1,1,1,0,0,1,0}},
      {{0,1,0,1,1,0,0,1,0,0,1,0,1,0,1}},
      {{1,0,1,0,0,1,1,0,1,1,0,1,0,0,0}},
      {{0,1,0,1,0,0,1,0,1,0,1,0,1,1,0}},
      {{1,0,1,0,1,1,0,0,0,1,0,1,0,0,1}},
      {{0,1,0,1,0,0,1,1,0,0,1,0,1,0,0}}
  }};


    Grid<20,15> grid(myTable);

    while (window.isOpen()) {
        while (const std::optional<Event> event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear(Color::White);
        grid.draw(window);
        window.display();
    }
  
  return 0;
}
