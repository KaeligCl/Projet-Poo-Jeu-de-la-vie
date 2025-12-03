#include "celluleMorte.hpp"
#include "celluleVivante.hpp"
#include "fichier.hpp"
#include "grille.hpp"
#include "drawable.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

int main() {
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
