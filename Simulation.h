#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>


#include "components.h"

class Simulation {
    private:
        Grid gridToSim; // Member variable to hold the grid for simulation

    public:
        Simulation(const Grid &) ;

        static Grid createnextGrid(const Grid& ) ;


    // Function to display the grid in the terminal within the Simulation class
        void displayGrid() const ;
};


#endif // SIMULATION_H