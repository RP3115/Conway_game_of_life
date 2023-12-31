#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <iostream>
#include <vector>

class Cell {
    private:
        int status; //0 or 1 
    public:
        Cell(int);

        int getValue() const;

        void setValue(int) ;

};

class Grid {
    private:
        friend class Simulation;
        std::vector< std::vector <Cell> > cells;

    public:
        Grid();
        Grid(int, int);

        // Function to get the value of a cell at a specific position
        int getCellValue(int, int) const ;

        // Function to set the value of a cell at a specific position
        void setCellValue(int, int, int) ;
};

class Simulation {
    private:
        Grid gridToSim; // Member variable to hold the grid for simulation

    public:
        Simulation(const Grid &) ;

        static Grid createnextGrid(const Grid& ) ;


    // Function to display the grid in the terminal within the Simulation class
        void displayGrid(const Grid&) const ;
};


#endif // COMPONENTS_H