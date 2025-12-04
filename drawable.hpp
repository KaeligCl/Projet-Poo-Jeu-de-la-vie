#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "cellule.hpp"
#include "celluleVivante.hpp"
#include "celluleMorte.hpp"
#include "grille.hpp"

static const sf::Color Grey(100, 100, 100);
static const sf::Color Blue(0, 0, 255);

struct Pos {
    float x;
    float y;
};

class Grid {
private:
    grille& data;
    float cellSize;
    float lineSize;
    Pos origin;

public:
    Grid(grille& table, float cellSize = 20.f, float lineSize = 2.f, Pos origin = {50.f, 50.f})
        : data(table), cellSize(cellSize), lineSize(lineSize), origin(origin) {}

    void draw(sf::RenderWindow& window) const {
        int hauteur = data.getHauteur();
        int largeur = data.getLargeur();

        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
                float x = origin.x + j * (cellSize + lineSize);
                float y = origin.y + i * (cellSize + lineSize);

                sf::RectangleShape cell({cellSize, cellSize});
                cell.setPosition(sf::Vector2f(x + lineSize, y + lineSize));

                if (data.getCellule(i, j)->getObstacle()){
                    cell.setFillColor(data.getCellule(i, j)->getEstVivant() ? Blue : sf::Color::Black);
                } else {
                    cell.setFillColor(data.getCellule(i, j)->getEstVivant() ? sf::Color::Green : Grey);
                }
                window.draw(cell);

                // lignes
                sf::RectangleShape vert({lineSize, cellSize + lineSize});
                vert.setFillColor(sf::Color::Black);
                vert.setPosition(sf::Vector2f(x, y));
                window.draw(vert);

                sf::RectangleShape hor({cellSize + lineSize, lineSize});
                hor.setFillColor(sf::Color::Black);
                hor.setPosition(sf::Vector2f(x, y));
                window.draw(hor);
            }
        }

        // bordures finales
        sf::RectangleShape borderVert({lineSize, hauteur * (cellSize + lineSize)});
        borderVert.setFillColor(sf::Color::Black);
        borderVert.setPosition(sf::Vector2f(origin.x + largeur * (cellSize + lineSize), origin.y));
        window.draw(borderVert);

        sf::RectangleShape borderHor({largeur * (cellSize + lineSize), lineSize});
        borderHor.setFillColor(sf::Color::Black);
        borderHor.setPosition(sf::Vector2f(origin.x, origin.y + hauteur * (cellSize + lineSize)));
        window.draw(borderHor);
    }
};
