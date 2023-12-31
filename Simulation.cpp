#include <iostream>
#include <fstream>
#include <vector>


#include "Simulation.h"
#include "components.h"

Simulation::Simulation(const Grid &grid) : gridToSim(grid) {}

static Grid Simulation::createnextGrid(const Grid& currGrid) {
    Grid nextGrid(currGrid);  // copy constructor for Grid  needed??

    for (int i = 0; i < currGrid.cells.size(); i++) {
        for (int j = 0; j < currGrid.cells[i].size(); j++) {
            int alive_neighbor = 0;
            int current_cell = currGrid.cells[i][j].getValue();

            // Counting alive cells in the row above
            if (i > 0 && j > 0 && currGrid.cells[i - 1][j - 1].getValue() == 1) alive_neighbor += 1;
            if (i > 0 && currGrid.cells[i - 1][j].getValue() == 1) alive_neighbor += 1;
            if (i > 0 && j < currGrid.cells[i].size() - 1 && currGrid.cells[i - 1][j + 1].getValue() == 1) alive_neighbor += 1;

            // Counting alive cells in the current row
            if (j > 0 && currGrid.cells[i][j - 1].getValue() == 1) alive_neighbor += 1;
            if (j < currGrid.cells[i].size() - 1 && currGrid.cells[i][j + 1].getValue() == 1) alive_neighbor += 1;

            // Counting alive cells in the row below
            if (i < currGrid.cells.size() - 1 && j > 0 && currGrid.cells[i + 1][j - 1].getValue() == 1) alive_neighbor += 1;
            if (i < currGrid.cells.size() - 1 && currGrid.cells[i + 1][j].getValue() == 1) alive_neighbor += 1;
            if (i < currGrid.cells.size() - 1 && j < currGrid.cells[i].size() - 1 && currGrid.cells[i + 1][j + 1].getValue() == 1) alive_neighbor += 1;

            // Implement the rules of Conway's Game of Life
            switch (current_cell) {
                case 1:
                    if (alive_neighbor == 2 || alive_neighbor == 3) {
                        nextGrid.cells[i][j].setValue(1);
                    } else {
                        nextGrid.cells[i][j].setValue(0);
                    }
                    break;
                case 0:
                    if (alive_neighbor == 3) {
                        nextGrid.cells[i][j].setValue(1);
                    } else {
                        nextGrid.cells[i][j].setValue(0);
                    }
                    break;
                default:
                    std::cout << "Unknown Character in 2D-Array" << std::endl;
            }
        }
    }

    return nextGrid; //not sure if correct
}


// Function to display the grid in the terminal within the Simulation class
void Simulation::displayGrid(const Grid& currGrid) const {
    for (const auto &row : currGrid.cells) {
        for (const auto &cell : row) {
            std::cout << cell.getValue() << " ";
        }
        std::cout << std::endl;
    }
}

