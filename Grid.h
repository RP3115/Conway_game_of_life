#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
#include "Cell.h"

class Grid {
  private:
    std::vector<std::vector<Cell>> _cells;
    int _rows;
    int _cols;
    std::string _filename;
  
  public:
    // Constructor
    Grid(int rows, int cols, std::string filename = "RandomGrid" );

    // Copy constructor
    Grid(const Grid& other);

    // Getter for accessing a specific cell
    const Cell& getCell(int row, int col) const;

    // Setter for modifying a specific cell
    void setCell(int row, int col, int state);

    // Getter for getting alive neighbors
    int get_aliveNeigbors(int row, int col) const;

    // Setter for modifying alive neighbors
    void set_neighbors(int row, int col, int neigbhors);

    //print grid
    void printGrid(bool saveGrid = false, int iteration = 0) const;

    //Randomly assign Alive or Dead state to existing grid cells.
    void randomizeGrid();

    //Getting Access to size of row and column
    size_t size_row() const;
    size_t size_col() const;

    //Change Name of Grid
    void changeName(std::string newName);

    //Extending Grid functions:
    void extendGridTOP();
    void extendGridBOTTOM();
    void extendGridLEFT();
    void extendGridRIGHT();
};

#endif



