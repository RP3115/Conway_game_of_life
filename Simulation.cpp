#include "Simulation.h"
#include <iostream>
#include <chrono>
#include <thread>

 Simulation::Simulation(){}

 void Simulation::update_Grid(Grid origin_Grid,int timesteps){
    
    for (int counter = 1; counter <= timesteps; counter++){

        //Check if Border extension is needed////////////////////////////////////////////////////////
        //Check if extension on left Border is needed:
        int alive_at_border = 0;
        for (auto i = 0; i < origin_Grid.size_row(); i++){                      
            if (origin_Grid.getCell(i,0).getState() == 1) alive_at_border +=1;
            else alive_at_border = 0;

            if (alive_at_border == 3){
                //std::cout << "new left Border needed" << std::endl;
                origin_Grid.extendGridLEFT();
                alive_at_border = 0;
                break;
            }
        }

        //Check if extension on right Border is needed:
        for (auto i = 0; i < origin_Grid.size_row(); i++){                      
            if (origin_Grid.getCell(i,origin_Grid.size_col()-1).getState() == 1) alive_at_border +=1;
            else alive_at_border = 0;

            if (alive_at_border == 3){
                //std::cout << "new right Border needed" << std::endl;
                origin_Grid.extendGridRIGHT();
                alive_at_border = 0;
                break;
            }
        }

        //Check if extension on top Border is needed:
        for (auto i = 0; i < origin_Grid.size_col(); i++){                      
            if (origin_Grid.getCell(0,i).getState() == 1) alive_at_border +=1;
            else alive_at_border = 0;

            if (alive_at_border == 3){
                //std::cout << "new top Border needed" << std::endl;
                origin_Grid.extendGridTOP();
                alive_at_border = 0;
                break;
            }
        }

        //Check if extension on bottom Border is needed:
        for (auto i = 0; i < origin_Grid.size_col(); i++){                      
            if (origin_Grid.getCell(origin_Grid.size_row()-1,i).getState() == 1) alive_at_border +=1;
            else alive_at_border = 0;

            if (alive_at_border == 3){
                //std::cout << "new bottom Border needed" << std::endl;
                origin_Grid.extendGridBOTTOM();
                alive_at_border = 0;
                break;
            }
        }
        
        Grid updated_Grid = origin_Grid;


        //Simulation logic / Count neigbhors /////////////////////////////////////////////////////////
        for (auto i = 0; i < origin_Grid.size_row(); i++)         
        { 
            for (auto j = 0; j < origin_Grid.size_col(); j++)  
            {   int alive_neighbor = 0;
                
                //Counting alive cells in row above
                if (i>0 && j>0 && origin_Grid.getCell(i-1, j-1).getState() == 1) alive_neighbor += 1;
                if (i>0 && origin_Grid.getCell(i-1,j).getState() == 1) alive_neighbor += 1;
                if (i>0 && j<origin_Grid.size_col() - 1 && origin_Grid.getCell(i-1, j+1).getState() == 1) alive_neighbor += 1;

                //Counting alive cells in current row   
                if (j>0 && origin_Grid.getCell(i,j-1).getState() == 1) alive_neighbor += 1;
                if (j<origin_Grid.size_col() - 1  && origin_Grid.getCell(i,j+1).getState() == 1) alive_neighbor += 1;

                //Counting alive cells in row bellow
                if (i<origin_Grid.size_row()-1 && j>0 && origin_Grid.getCell(i+1,j-1).getState() == 1) alive_neighbor += 1;
                if (i<origin_Grid.size_row()-1 && origin_Grid.getCell(i+1,j).getState() == 1) alive_neighbor += 1;
                if (i<origin_Grid.size_row()-1 && j<origin_Grid.size_col() - 1 && origin_Grid.getCell(i+1,j+1).getState() == 1) alive_neighbor += 1;


                //std::cout << alive_neighbor << " ";

                //implement the rules of game of life
                if (origin_Grid.getCell(i,j).getState() == true) {
                    if(alive_neighbor == 2 || alive_neighbor == 3) updated_Grid.setCell(i,j,1);  //1,0 to alive dead!
                    else updated_Grid.setCell(i,j,0);
                } else {
                    if( alive_neighbor == 3) updated_Grid.setCell(i,j,1);  //1,0 to alive, dead!
                    else updated_Grid.setCell(i,j,0);
                }

            }     

            //std::cout << std::endl; 
            
        }

        //Windows 
        // system("cls"); //clears the terminal

        //Linux 
        system("clear"); //clears the terminal

        std::cout << "Updated Grid -- Timestep " << counter <<std::endl;
        updated_Grid.printGrid();
        origin_Grid = updated_Grid;
        std::this_thread::sleep_for(std::chrono::seconds(2));

    }

 }

