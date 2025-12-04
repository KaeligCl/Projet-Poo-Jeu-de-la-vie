#include "fichier.hpp"
#include "regles.hpp"
#include "grille.hpp"
#include "drawable.hpp"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
using namespace std;

int main()
{
    Fichier f;
    Regle r;
    cout << "Bienvenue dans le jeu de la vie"
    << "\nMettez le chemin d'acces de la matrice originelle (utilisez des /): " <<endl;
    string chemin;
    getline(cin, chemin);

    std::filesystem::path p(chemin);
    std::string dossier = p.parent_path().string();
    std::string base = p.stem().string();

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
        grille g = f.lireFichier(chemin);

        for (int i = 0; i < nbrMaxItération; i++)
        {
            std::string sortie = dossier + "/" + base + "_" + std::to_string(i) + ".txt";
            f.creerFichier(g, sortie);
            r.etatSuivant(g);
        }
    }

    else if (choixMode == 2)
    {
        cout << "Vous avez choisi le mode interface graphique" << endl;
        grille g = f.lireFichier(chemin);
        sf::RenderWindow window(sf::VideoMode({800, 600}), "Grid Window");

        int iterationActuelle = 0;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::White);
            if (iterationActuelle < nbrMaxItération)
            {
                r.etatSuivant(g);
                iterationActuelle++;
            }
            Grid grilleAffichage(g);
            grilleAffichage.draw(window);
            window.display();

            sf::sleep(sf::milliseconds(200)); //delai entre 2 itérations
        }
    }
    return 0;

}
