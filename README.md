# GameOfLife: 
Conway's Game Of Life is an easy realization of a cellular automaton, which models dynamic but discrete systems.
In this project, we create a simulation that realizes such systems.

# Sprint 2:

Definition of "Done"
* The code is refactored into classes, and OOP principles are observed. 
* Classes for `Cell` and `Grid` have been added.
* The simulation logic is stored in a separate class, with experimentation for a second update rule for all cells.
* A workflow allowing the user to specify a file to load via the command line is implemented. This workflow is also stored in a separate class.
* The option to create a random grid is added to the workflow, using the existing method as a reference.
* The user can specify the number of time steps for which the simulation runs and can start the simulation.
* The program does not exit after the last time step.
* The simulation is extended to an infinite grid: if a boundary of the grid is reached, additional rows/columns are added.
* (Optional) The simulation is animated in the terminal window, achieved by clearing the terminal and adding delays between simulation steps.


## Building

Build GameOfLife in your terminal with:

```shell
mkdir build
cd build
cmake ..
make
```

## Running

Run GameOfLife in your terminal with:

```shell
./GameOfLife
```

## Example output

1. Choose if you want to use a testfile or create an own random Grid

```shell
**********Choose**********
Press (r) for creating a random grid
Press (t) for using a testfile
```

2. Option 1: Random-Grid:

Enter number of rows, columns and timesteps. Right after entering those Informations, the Simulation will start!

```shell
Enter the number of rows: 3
Enter the number of columns: 3
Enter the number of timesteps: 2
Creating a random grid...
1 0 1 
1 1 1 
0 0 1 

Simulating the random grid for 2 timesteps...
Updated Grid -- Timestep 1
1 0 1 0 
1 0 1 1 
0 0 1 0 

Updated Grid -- Timestep 2
0 0 1 1 
0 0 1 1 
0 1 1 1 

Do you want to start a new simulation? (y/n): 
```
After Simulation is finished, you can start again from the beginning, after entering "y".

3. Option 2: Testfile:

Enter name of the file for input. <!-- and timesteps. Right after entering those Informations, the Simulation will start! -->

File syntax: 
First line should contain number of rows and columns and subsequent lines should have the initial grid.
```shell
4 4
0 1 0 0
1 1 0 1
1 1 0 0
0 1 1 1
```

Enter the number of timesteps. Right after entering this Informations, the Simulation will start!
```shell
The Initial state of our Grid is:
0 1 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Enter the number of timesteps: 3
Simulating the grid for 3 timesteps...
Updated Grid -- Timestep 1
1 1 1 0
0 0 0 0
0 0 0 1
1 1 1 0
0 0 1 0

Updated Grid -- Timestep 2
0 1 0 0
0 1 0 0
0 1 1 0
0 1 1 0
0 1 1 1
0 0 1 0

Updated Grid -- Timestep 3
0 0 0 0
1 1 0 0
1 0 0 0
1 0 0 0
0 0 0 1
0 1 1 1

Do you want to start a new simulation? (y/n):
```