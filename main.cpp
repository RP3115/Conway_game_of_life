#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib> 
#include <ctime>   

#include "components.h"
//#include "Simulation.h"

class Workflow {

};
void take_input(int x,int y, Grid &myGrid){
    int k=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            std::cin>>k;
            myGrid.setCellValue(i,j,k);
        }
    }
}

int main() {
    // Testing code -->
    // const int rows = 5;
    // const int cols = 5;
    int rows,cols;
    std::cin>>rows>>cols;
    // Create a grid with 3 rows and 4 columns
    Grid myGrid(rows, cols);

    // Set some cell values
    take_input(rows,cols,myGrid);
    // Display the grid
    Simulation mySimulation(myGrid);

    // Display the initial grid
    std::cout << "Initial Grid:" << std::endl;
    mySimulation.displayGrid(myGrid);
    std::cout << std::endl;

    // Call createnextGrid to generate the next state of the grid
    Grid nextGrid = mySimulation.createnextGrid(myGrid);

    // Display the next state of the grid
    std::cout << "Next Grid:" << std::endl;
    // Simulation nextSimulation(nextGrid);
    mySimulation.displayGrid(nextGrid);
    while(true){
        // myGrid=nextGrid;
        Grid nextGrid = mySimulation.createnextGrid(nextGrid);

        // Display the next state of the grid
        std::cout << "Next Grid:" << std::endl;
        // Simulation nextSimulation(nextGrid);
        mySimulation.displayGrid(nextGrid);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
    
}

