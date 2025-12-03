#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <memory>

#include "cellule.hpp"
#include "celluleVivante.hpp"
#include "celluleMorte.hpp"

struct Pos {
    float x;
    float y;
};

template <size_t Rows, size_t Cols>
class Grid {
private:
    grille data;

    float cellSize;
    float lineSize;
    Pos origin;

public:
    Grid(const grille& table,
         float cellSize = 20.f,
         float lineSize = 2.f,
         Pos origin = {50.f, 50.f})
        : cellSize(cellSize), lineSize(lineSize), origin(origin)
    {

        /* pour le fichier Files
        for (size_t i = 0; i < table.getHauteur(); i++) {
            for (size_t j = 0; j < table.getLargeur(); j++) {
                if (table[i][j] == 1)
                    data[i][j] = std::make_shared<celluleVivante>();
                else
                    data[i][j] = std::make_shared<celluleMorte>();
            }
        }
        */
    }

    void draw(sf::RenderWindow& window) const {
        for (size_t i = 0; i < table.getHauteur(); i++) {
            for (size_t j = 0; j < table.getLargeur(); j++) {

                float x = origin.x + j * (cellSize + lineSize);
                float y = origin.y + i * (cellSize + lineSize);

                sf::RectangleShape cell({cellSize, cellSize});
                cell.setPosition(sf::Vector2f(x + lineSize, y + lineSize));

                cell.setFillColor(
                    data[i][j]->getEstVivant() ? sf::Color::Green : sf::Color::Black
                );

                window.draw(cell);

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

        sf::RectangleShape borderVert({lineSize, table.getHauteur() * (cellSize + lineSize)});
        borderVert.setFillColor(sf::Color::Black);
        borderVert.setPosition(sf::Vector2f(origin.x + Cols * (cellSize + lineSize), origin.y));
        window.draw(borderVert);

        sf::RectangleShape borderHor({table.getLargeur() * (cellSize + lineSize), lineSize});
        borderHor.setFillColor(sf::Color::Black);
        borderHor.setPosition(sf::Vector2f(origin.x, origin.y + Rows * (cellSize + lineSize)));
        window.draw(borderHor);
    }
};
