#include "Grid.h"
#include <vector>
#include <iostream>


Grid::Grid(int rows, int cols) : _cells(rows, std::vector<Cell>(cols)), _rows(rows), _cols(cols) {}

Grid::Grid(const Grid& other) : _cells(other._cells.size()) {
    for (std::size_t i = 0; i < other._cells.size(); ++i) {
        _cells[i].resize(other._cells[i].size());
        for (std::size_t j = 0; j < other._cells[i].size(); ++j) {
            _cells[i][j] = other._cells[i][j]; 
        }
    }
}

const Cell& Grid::getCell(int row, int col) const {
    return _cells[row][col];
}

void Grid::setCell(int row, int col, int state) {
    _cells[row][col].setState(state);
}

void Grid::printGrid() const {
    for (const auto& row : _cells) {
        for (const auto& cell : row) {
            std::cout << cell.getState() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Grid::randomizeGrid() {
    for (std::size_t i = 0; i < _cells.size(); ++i) {
        for (std::size_t j = 0; j < _cells[i].size(); ++j) {
            _cells[i][j].set_random_State();
        }
    }
}

size_t Grid::size_row() const {
    return _cells.size();
}

size_t Grid::size_col() const {
    return (_cells.size() > 0) ? _cells[0].size() : 0;
}

void Grid::extendGridTOP() {
    // Create a new row with the same number of columns as the existing grid
    std::vector<Cell> newRow(size_col(), Cell(0));
    // Add the new row to the top of the grid
    _cells.insert(_cells.begin(), newRow);
}

void Grid::extendGridBOTTOM() {
    std::vector<Cell> newRow(size_col(), Cell(0));
    _cells.insert(_cells.end(), newRow);
}

void Grid::extendGridLEFT() {
    // Create a new column with the same number of rows as the existing grid
    std::vector<Cell> newColumn(size_row(), Cell(0));
    for (auto& row : _cells) {
        row.insert(row.begin(), newColumn.front());
    }
}

void Grid::extendGridRIGHT() {
    std::vector<Cell> newColumn(size_row(), Cell(0));
    for (auto& row : _cells) {
        row.insert(row.end(), newColumn.front());
    }
}




