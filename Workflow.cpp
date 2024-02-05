#include "Workflow.h"
#include <iostream>

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
    mySimulation.update_Grid(myGrid, timesteps);
}

Grid& Workflow::givegrid(){
    return myGrid;
}