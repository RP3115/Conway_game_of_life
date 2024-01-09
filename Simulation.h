#ifndef SIMULATION_H
#define SIMULATION_H

#include "Grid.h"


class Simulation{

     public:
        Simulation();

        //Simulation logic
        void update_Grid(Grid, int timesteps);
};

#endif