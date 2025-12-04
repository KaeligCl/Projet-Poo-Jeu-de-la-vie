#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "cellule.h"
#include "celluleVivante.h"
#include "celluleMorte.h"
#include "grille.h"

static const sf::Color Grey(100, 100, 100);
static const sf::Color Blue(0, 0, 255);

struct Form
{
    float l, L;
};

class Grid {
private:
    grille& data;
    Form cellSize;
    float lineSize;
    int windowWidth;
    int windowHeight;

public:
    Grid(grille& table, int windowWidth, int windowHeight)
        : data(table),windowWidth(windowWidth),windowHeight(windowHeight), cellSize({0,0}), lineSize(1.f) {}

    void draw(sf::RenderWindow& window) {
        int hauteur = data.getHauteur();
        int largeur = data.getLargeur();

        float lineSize = 1.f;
        cellSize.l = (windowWidth  - (largeur + 1) * lineSize) / largeur;
        cellSize.L = (windowHeight - (hauteur + 1) * lineSize) / hauteur;

        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
                float x = j * (cellSize.l + lineSize);
                float y = i * (cellSize.L + lineSize);

                sf::RectangleShape cell({cellSize.l, cellSize.L});
                cell.setPosition(sf::Vector2f(x + lineSize, y + lineSize));

                if (data.getCellule(i, j)->getObstacle()){
                    cell.setFillColor(data.getCellule(i, j)->getEstVivant() ? Blue : sf::Color::Black);
                } else {
                    cell.setFillColor(data.getCellule(i, j)->getEstVivant() ? sf::Color::Green : Grey);
                }
                window.draw(cell);

                // lignes
                sf::RectangleShape vert({lineSize, cellSize.L + lineSize});
                vert.setFillColor(sf::Color::Black);
                vert.setPosition(sf::Vector2f(x, y));
                window.draw(vert);

                sf::RectangleShape hor({cellSize.l + lineSize, lineSize});
                hor.setFillColor(sf::Color::Black);
                hor.setPosition(sf::Vector2f(x, y));
                window.draw(hor);
            }
        }

        // bordures finales
        sf::RectangleShape borderVert({lineSize, hauteur * (cellSize.L + lineSize)});
        borderVert.setFillColor(sf::Color::Black);
        borderVert.setPosition(sf::Vector2f(largeur * (cellSize.l + lineSize),0));
        window.draw(borderVert);

        sf::RectangleShape borderHor({largeur * (cellSize.l + lineSize), lineSize});
        borderHor.setFillColor(sf::Color::Black);
        borderHor.setPosition(sf::Vector2f(0, hauteur * (cellSize.L + lineSize)));
        window.draw(borderHor);
    }
};
