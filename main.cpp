#include "celluleMorte.hpp"
#include "celluleVivante.hpp"
#include "fichier.hpp"
#include "grille.hpp"
#include "drawable.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    /*Fichier f;
    regle r;
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
    }*/




    
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Grid Window");

    Fichier f;
    grille g = f.lireFichier("monFichier.txt");

    Grid grilleAffichage(g);

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);
        grilleAffichage.draw(window);
        window.display();
    }

    return 0;
}
