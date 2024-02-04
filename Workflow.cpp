#include "Workflow.h"
#include <iostream>
#include <fstream>


Workflow::Workflow(int rows, int cols) : myGrid(rows, cols) {}
void Workflow::printgrid() const {
    myGrid.printGrid();
}
void Workflow::createRandomGrid() {
    std::cout << "Creating a random grid..." << std::endl;
    myGrid.randomizeGrid();
}

void Workflow::simulateGrid(int timesteps) {
    std::cout << "Simulating the grid for " << timesteps << " timesteps..." << std::endl;
    
    //Option to save simulated Grids
    char choice;
    bool saveSims = false;
    std::cout << "**********Choose**********\n"
              << "Press (y) for saving all simulations in Pbm-Files\n"
              << "Press (n) for continuing without saving" << std::endl;
    std::cin >> choice;

    if (choice == 'y')
    {

        saveSims = true;
    }

    else saveSims = false;

    mySimulation.update_Grid(myGrid, timesteps, saveSims);
}


Grid& Workflow::givegrid(){
    return myGrid;
}