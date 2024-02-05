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
  
  public:
    // Constructor
    Grid(int rows, int cols);

    // Copy constructor
    Grid(const Grid& other);

    // Getter for accessing a specific cell
    const Cell& getCell(int row, int col) const;

    // Setter for modifying a specific cell
    void setCell(int row, int col, int state);

    //print grid
    void printGrid() const;

    //Randomly assign Alive or Dead state to existing grid cells.
    void randomizeGrid();

    //Getting Access to size of row and column
    size_t size_row() const;
    size_t size_col() const;

    //Extending Grid functions:
    void extendGridTOP();
    void extendGridBOTTOM();
    void extendGridLEFT();
    void extendGridRIGHT();
};

#endif



