#include "drawable.hpp"

template <size_t Rows, size_t Cols>
void Grid<Rows, Cols>::draw(RenderWindow& window) const {
    for (size_t i = 0; i < Rows; i++) {
        for (size_t j = 0; j < Cols; j++) {
            float x = origin.x + j * (cellSize + lineSize);
            float y = origin.y + i * (cellSize + lineSize);

            RectangleShape cell({cellSize, cellSize});
            cell.setPosition(Vector2f(x + lineSize, y + lineSize));

            // couleur en fonction de la cellule
            cell.setFillColor(
                data[i][j]->getEstVivant() ? Color::Green : Color::Black
            );

            window.draw(cell);

            // ligne verticale
            RectangleShape vert({lineSize, cellSize + lineSize});
            vert.setFillColor(Color::Black);
            vert.setPosition(Vector2f(x, y));
            window.draw(vert);

            // ligne horizontale
            RectangleShape hor({cellSize + lineSize, lineSize});
            hor.setFillColor(Color::Black);
            hor.setPosition(Vector2f(x, y));
            window.draw(hor);
        }
    }

    // bordures finales
    RectangleShape borderVert({lineSize, Cols * (cellSize + lineSize)});
    borderVert.setFillColor(Color::Black);
    borderVert.setPosition(Vector2f(origin.x + Rows * (cellSize + lineSize), origin.y));
    window.draw(borderVert);

    RectangleShape borderHor({Rows * (cellSize + lineSize), lineSize});
    borderHor.setFillColor(Color::Black);
    borderHor.setPosition(Vector2f(origin.x, origin.y + Cols * (cellSize + lineSize)));
    window.draw(borderHor);
}

instanciation explicite du template
template class Grid<5,5>;
