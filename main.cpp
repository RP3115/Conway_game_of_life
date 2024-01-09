#include "Workflow.h"
#include <iostream>

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
      myWorkflow.simulateRandomGrid(timesteps);

    } else if (choice == 't') {
      std::cout << "Choice: Testfile!" << std::endl;

    //////////////////////////////////////////////////////
    //                                                  //
    //                                                  //
    //                                                  //
    //                 TO Do RONAK                      //
    //                                                  //
    //       (Create a Workflow as next step)           //
    //                                                  //
    //////////////////////////////////////////////////////

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
