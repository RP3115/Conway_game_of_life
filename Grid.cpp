#include "Grid.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>




Grid::Grid(int rows, int cols, std::string filename) : _cells(rows, std::vector<Cell>(cols)), _rows(rows), _cols(cols), _filename(filename){}

Grid::Grid(const Grid& other) : _cells(other._cells.size()) {
    for (std::size_t i = 0; i < other._cells.size(); ++i) {
        _cells[i].resize(other._cells[i].size());
        for (std::size_t j = 0; j < other._cells[i].size(); ++j) {
            _cells[i][j] = other._cells[i][j]; 
        }
    }

    // Copy the filename
    _filename = other._filename;
}

const Cell& Grid::getCell(int row, int col) const {
    return _cells[row][col];
}

void Grid::setCell(int row, int col, int state) {
    _cells[row][col].setState(state);
}

int Grid::get_aliveNeigbors(int row, int col) const{
    return _cells[row][col].get_alive_neighbors();
}

void Grid::set_neighbors(int row, int col, int neigbhors) {
    _cells[row][col].set_neighbors(neigbhors);
}

void Grid::printGrid(bool saveGrid, int iteration) const {
    if (saveGrid == true) {

        std::string filename = _filename;
        namespace fs = std::filesystem;
        // Get the current working directory
        fs::path currentPath = fs::current_path();

      // Convert the path to a string
      std::string currentPathStr = currentPath.string();

      // Delete the last 6 characters from the string (go back to original project directory! Away from build)
      currentPathStr.erase(currentPathStr.size() - 6);

        fs::path filePath = fs::path(currentPathStr) / "Testfiles" / (filename + "_" + std::to_string(iteration) + ".pbm");

        std::ofstream outFile(filePath.string(), std::ios::out | std::ios::binary);


        // Write PBM header
        outFile << "P1\n";  // PBM magic number
        outFile << _cells[0].size() << " " << _cells.size() << "\n";

        
        for (const auto& row : _cells) {
            for (const auto& cell : row) {

                //Printing white quares (=Alive) and black squares (=Dead) to terminal
                if (cell.getState() == 0) std::cout << "\033[30;40m■\033[0m ";
                else std::cout << "\033[97;40m■\033[0m ";

                //Printing to file
                outFile << cell.getState() <<  " ";

            }
            std::cout << std::endl;
            outFile << "\n";

        }
        std::cout << std::endl;

        outFile.close();
    }

    else {
        
        for (const auto& row : _cells) {
            for (const auto& cell : row) {

                //Printing white quares (=Alive) and black squares (=Dead) to terminal
                if (cell.getState() == 0) std::cout << "\033[30;40m■\033[0m ";
                else std::cout << "\033[97;40m■\033[0m ";

            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    }
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

void Grid::changeName(std::string newName){
    _filename = newName.substr(0, newName.size() - 4);
};

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




