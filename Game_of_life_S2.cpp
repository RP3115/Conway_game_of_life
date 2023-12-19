#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib> 
#include <ctime>   

class Cell {
    private:
        int status; //0 or 1 

    public:
        Cell(int isalive = 0) : status(isalive) {}

        int getValue() const {
            return status;
        }

        void setValue(int isalive) {
            status = isalive;
        }

};

class Grid {
    private:
        friend class Simulation;
        std::vector< std::vector <Cell> > cells;

    public:
        Grid() {}
        Grid(int rows, int cols) : cells(rows, std::vector<Cell>(cols)) {}

        // Function to get the value of a cell at a specific position
        int getCellValue(int row, int col) const {
            return cells[row][col].getValue();
        }

        // Function to set the value of a cell at a specific position
        void setCellValue(int row, int col, int status) {
            cells[row][col].setValue(status);
        }
};

class Simulation {
    private:
        Grid gridToSim; // Member variable to hold the grid for simulation

    public:
        Simulation(const Grid &grid) : gridToSim(grid) {}

        static Grid createnextGrid(const Grid& currGrid) {
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
        void displayGrid() const {
            for (const auto &row : gridToSim.cells) {
                for (const auto &cell : row) {
                    std::cout << cell.getValue() << " ";
                }
                std::cout << std::endl;
            }
        }
};

class Workflow {

};





int main() {
    // Testing code -->
    const int rows = 5;
    const int cols = 5;

    // Create a grid with 3 rows and 4 columns
    Grid myGrid(rows, cols);

    // Set some cell values
    myGrid.setCellValue(1, 2, 1);
    myGrid.setCellValue(2, 2, 1);
    myGrid.setCellValue(3, 2, 1);

    // Display the grid
    Simulation mySimulation(myGrid);

    // Display the initial grid
    std::cout << "Initial Grid:" << std::endl;
    mySimulation.displayGrid();
    std::cout << std::endl;

    // Call createnextGrid to generate the next state of the grid
    Grid nextGrid = mySimulation.createnextGrid(myGrid);

    // Display the next state of the grid
    std::cout << "Next Grid:" << std::endl;
    Simulation nextSimulation(nextGrid);
    nextSimulation.displayGrid();

    return 0;
    
}

