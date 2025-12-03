#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <vector>
#include <memory>

#include "../cellule.hpp"

using namespace sf;

struct Pos {
    float x;
    float y;
};

template <size_t Rows, size_t Cols>
class Grid {
private:
    std::vector<std::vector<std::shared_ptr<Cellule>>> data;
    float cellSize;
    float lineSize;
    Pos origin;

public:
    Grid(const std::vector<std::vector<std::shared_ptr<Cellule>>>& table,
         float cellSz = 20.f,
         float lineSz = 2.f,
         Pos org = {50.f, 50.f})
        : data(table), cellSize(cellSz), lineSize(lineSz), origin(org) {}

    void draw(RenderWindow& window) const;
};
