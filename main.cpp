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
        unsigned int windowWidth = 600;
        unsigned int windowHeight = 800;
        sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "Grid Window");
        Grid grilleAffichage(g, windowWidth, windowHeight);

        int iterationActuelle = 0;
        bool autoplay = false;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space)
                        autoplay = !autoplay;
                    else if (event.key.code == sf::Keyboard::Right && iterationActuelle < nbrMaxItération) {
                        r.etatSuivant(g);
                        iterationActuelle++;
                    }
                }
            }

            if (autoplay && iterationActuelle < nbrMaxItération) {
                r.etatSuivant(g);
                iterationActuelle++;
                sf::sleep(sf::milliseconds(200));
            }

            window.clear(sf::Color::White);
            grilleAffichage.draw(window);
            window.display();
        }
    }
    return 0;

}
