
#include "drawable.hpp"

Grid::draw(RenderWindow& window) const {
    // Parcourir chaque cellule
    for (size_t i = 0; i < Rows; i++) {
        for (size_t j = 0; j < Cols; j++) {
            float x = origin.x + j * (cellSize + lineSize);
            float y = origin.y + i * (cellSize + lineSize);

            // Cellule
            RectangleShape cell({cellSize, cellSize});
            cell.setPosition(Vector2f(x + lineSize, y + lineSize));
            cell.setFillColor(data[i][j] == 1 ? Color::Green : Color::Black);
            window.draw(cell);

            // Lignes verticales et horizontales
            RectangleShape vert({lineSize, cellSize + lineSize});
            vert.setFillColor(Color::Black);
            vert.setPosition(Vector2f(x, y));
            window.draw(vert);

            RectangleShape hor({cellSize + lineSize, lineSize});
            hor.setFillColor(Color::Black);
            hor.setPosition(Vector2f(x, y));
            window.draw(hor);
        }
    }

    // Bordures extérieures
    RectangleShape borderVert({lineSize, Cols * (cellSize + lineSize)});
    borderVert.setFillColor(Color::Black);
    borderVert.setPosition(Vector2f(origin.x + Rows * (cellSize + lineSize), origin.y));
    window.draw(borderVert);

    RectangleShape borderHor({Rows * (cellSize + lineSize), lineSize});
    borderHor.setFillColor(Color::Black);
    borderHor.setPosition(Vector2f(origin.x, origin.y + Cols * (cellSize + lineSize)));
    window.draw(borderHor);
};

int main() {
    RenderWindow window(VideoMode({800, 600}), "Grid Window");

    std::array<std::array<int, 5>, 5> myTable = {{
        {{0, 0, 0, 0, 0}},
        {{0, 1, 1, 0, 0}},
        {{0, 1, 0, 1, 1}},
        {{0, 1, 0, 0, 0}},
        {{1, 0, 0, 0, 1}}
    }};

    Grid<5, 5> grid(myTable);

    while (window.isOpen()) {
        while (const std::optional<Event> event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear(Color::White);
        grid.draw(window);  // dessine la grille
        window.display();
    }
}
