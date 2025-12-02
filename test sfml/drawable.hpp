#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include "cellule.hpp"
#include <vector>
using namespace sf;

struct Pos {
    float x;
    float y;
};

template <size_t Rows, size_t Cols>

class Grid {
    private:
        vector<vector<shared_ptr<Cellule>>> data;;
        
        float cellSize;
        float lineSize;
        Pos origin;
    
    public:
        Grid(const vector<vector<shared_ptr<Cellule>>>)
        : data(table), cellSize(20.f), lineSize(2.f), origin(Pos{50.f, 50.f}) {}
        void draw(RenderWindow& window) const;
};