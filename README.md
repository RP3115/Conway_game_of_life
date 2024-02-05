# Introduction to Game of Life:
This project was made as a part of course Advanced Programming by Ronak ([go68sor@mytum.de](mailto:go68sor@mytum.de)) and Samuel ([go68yug@mytum.de](mailto:go68yug@mytum.de))

[Conway's Game Of Life](https://de.wikipedia.org/wiki/Conways_Spiel_des_Lebens) is an easy realization of a cellular automaton, which models dynamic but discrete systems. 

To gain a more comprehensive and detailed understanding of the idea, you can visit the original project concept.
https://gitlab.lrz.de/tum-i05/public/advprog-project-ideas/-/blob/master/game-of-life/gameoflife.md?ref_type=heads

In this project, we create a simulation that realizes such systems.
Rules:

A living cell
* stays alive, if it hast exact 2 or 3 neighbors
* dies due to loneliness if it has fewer neighbors
* dies due to overpopulation if it has more neighbors

A dead cell
* will be reborn if it has exactly 3 neighbors
* remains dead otherwise

[Conway's Game Of Life](https://de.wikipedia.org/wiki/Conways_Spiel_des_Lebens) is an easy realization of a cellular automaton, which models dynamic but discrete systems. 
In this project, we create a simulation that realizes such systems.
Rules:

A living cell
* stays alive, if it hast exact 2 or 3 neighbors
* dies due to loneliness if it has fewer neighbors
* dies due to overpopulation if it has more neighbors

# Sprint 3:

Definition of "Done"
* The simulation does not use more memory than required (see optional last item, which is an extension of this)
* A better file format is used (look at the PBM file format) and grids can be saved in this file format
* The workflow includes the option to save the grid at every time step as an image file
* Grids are saved correctly (maybe using the format grid_i.pbm ; open the files locally to see if the format is correctly implemented)
* Unit test are implemented to test the dynamic grid size
* A CMakelists or Makefile that builds and tests the application is created

## Cloning

For cloning the project, the submodul 'googletest' is needed!

```shell
git clone --branch version3 https://gitlab.lrz.de/advprog2023/29.git
cd 29
git submodule update --init --recursive
```


## Building

Build GameOfLife in your terminal with:

```shell
mkdir build
cd build
cmake ..
make
```

## Running

Running the game:
```shell
./GameOfLife 
```

Running Unit Test:
```shell
./DynamicGridtest
```

## Example output

1. Choose if you want to use a testfile or create an own random Grid

```shell
**********Choose**********
Press (r) for creating a random grid
Press (t) for using a testfile
```

2. Option 1: Random-Grid:

Enter number of rows, columns and timesteps. Right after entering those Informations, the random grid gets created. You now are able to decide if you want to save your generated Grids in a .pbm-format. If you do so, all files get saved in Folder 'Testfiles'.

```shell
Enter the number of rows: 3
Enter the number of columns: 3
Enter the number of timesteps: 4
Creating a random grid...
■   ■ 
■ ■ ■ 
    ■ 

Simulating the grid for 4 timesteps...
**********Choose**********
Press (y) for saving all simulations in Pbm-Files
Press (n) for continuing without saving
```

Note: In terminal white cells = Alive, in the pbm-format its other way around due to better visibility! Here in the README it’s not possible to show you the differet colors, but I think you got the idea how it should look like later.

```shell
Updated Grid -- Timestep 1
■   ■ 
■   ■ ■ 
    ■ 

Updated Grid -- Timestep 2
    ■ ■ 
    ■ ■ 
  ■ ■ ■ 

Updated Grid -- Timestep 3
    ■ ■   
        ■ 
  ■   ■   
    ■     

Updated Grid -- Timestep 4
      ■   
        ■ 
    ■ ■   
    ■       

Do you want to start a new simulation? (y/n): 
```
After Simulation is finished, you can start again from the beginning, after entering "y".

3. Option 2: Testfile:

Enter name of the file for input. <!-- and timesteps. Right after entering those Informations, the Simulation will start! -->
The File has to be saved in the 'Testfile'-direktor! Currently there is only the file 'Testfile.pbm' saved. But feel free to create own files!
```shell
Testfile.pbm
```

File syntax: 
First line should contain number of rows and columns and subsequent lines should have the initial grid.
```shell
Choice: Testfile!
Input the name of the file: 
Testfile.pbm
The Initial state of our Grid is:
                             
                             
                             
              ■              
            ■ ■ ■            
          ■ ■ ■ ■ ■          
        ■ ■       ■ ■        
      ■ ■ ■       ■ ■ ■      
        ■ ■       ■ ■        
          ■ ■ ■ ■ ■          
            ■ ■ ■            
              ■              
                             
                             
                             
```

Enter the number of timesteps. Right after entering this Informations, you can decide if you want to save the files before the Simulation starts!

# Cleaning the directory 
Not necessary if you use the linux building instruction!
Just use the function :
```shell
make clean
```