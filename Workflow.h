#ifndef WORKFLOW_H
#define WORKFLOW_H

#include "Grid.h"
#include "Simulation.h"

class Workflow {
private:
    Grid myGrid;
    Simulation mySimulation;

public:
    Workflow(int rows, int cols);

    void createRandomGrid();
    // void simulateRandomGrid(int timesteps);
    void simulateGrid(int timesteps);
    void printgrid() const;
    Grid& givegrid();
};

#endif
