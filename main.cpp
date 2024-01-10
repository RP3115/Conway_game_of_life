#include "Workflow.h"
#include <iostream>
#include <filesystem>
#include <fstream>


int main() {
  char choice;
  do {
    std::cout << "**********Choose**********\n"
              << "Press (r) for creating a random grid\n"
              << "Press (t) for using a testfile" << std::endl;

    std::cin >> choice;  

    if (choice == 'r') {
      // Ask the user for the number of rows
      std::cout << "Enter the number of rows: ";
      int rows;
      std::cin >> rows;

      // Ask the user for the number of columns
      std::cout << "Enter the number of columns: ";
      int cols;
      std::cin >> cols;

      // Ask the user for the number of timesteps
      std::cout << "Enter the number of timesteps: ";
      int timesteps;
      std::cin >> timesteps;

      // Create an instance of Workflow with the specified rows and columns
      Workflow myWorkflow(rows, cols);

      // Perform the workflow for a random grid
      myWorkflow.createRandomGrid();
      myWorkflow.printgrid();
      myWorkflow.simulateGrid(timesteps);

    } else if (choice == 't') {

    std::cout << "Choice: Testfile!" <<std::endl<<"Input the name of the file: "<< std::endl;
    std::string filename;std::cin>>filename;
    
    // Get the current working directory
    namespace fs = std::filesystem;
    fs::path currentPath = fs::current_path();

    // Construct the full path to the file
    fs::path filePath = currentPath / filename;
    std::ifstream inputFile(filePath.string());

    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    int row,col;
    //int timesteps;
    std::getline(inputFile,line);
    std::istringstream rc(line);
        int num;
        rc>>num;row=num;
        rc>>num;col=num;
        // rc>>num;timesteps=num;
    Workflow myWorkflow(row,col);
    Grid& g=myWorkflow.givegrid();
    int i=0;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int value;
        int j=0;
        while (iss >> value) {
            g.setCell(i,j,value);
            j++;
        }
        i++;
    }

    inputFile.close();
    //end of input
    std::cout<<"The Initial state of our Grid is:"<<std::endl;
    myWorkflow.printgrid();
    std::cout << "Enter the number of timesteps: ";
    int timesteps;
    std::cin >> timesteps;
    myWorkflow.simulateGrid(timesteps);
    } else {
      std::cout << "It's fine if you cannot make up your mind. Maybe another time then...\n";
      std::exit(EXIT_FAILURE);
    }

    // Ask the user if they want to start a new simulation
    std::cout << "Do you want to start a new simulation? (y/n): ";
    std::cin >> choice;

  } while (choice == 'y' || choice == 'Y');

  std::cout << "Exiting the program. Goodbye!\n";

  return 0;
}
