#include <gtest/gtest.h>
#include "Simulation.h"
#include "Grid.h"

class GridTest : public testing::Test {
    public:
        Simulation* Testsimulation;
        Grid* Testgrid;
        
        GridTest(){
            Testsimulation = new Simulation();
            Testgrid = new Grid(3, 3, "Testgrid"); 
        }

        ~GridTest(){
            delete Testgrid;
            delete Testsimulation;
        }

};

TEST_F(GridTest, FirstCheck) {

    //Checking with empty Matrix:
    //    0 0 0
    //    0 0 0
    //    0 0 0
    Testsimulation->dynymic_gridsize(*Testgrid);

    //Expected: No Changes --> 3 Cols, 3 Rows
    EXPECT_EQ(3, Testgrid->size_col());
    EXPECT_EQ(3, Testgrid->size_row());
}

TEST_F(GridTest, SecondCheck) {
    
    Testgrid->setCell(0,0,1);
    Testgrid->setCell(0,1,1);
    Testgrid->setCell(0,2,1);
    //Checking  Matrix:
    //    1 1 1
    //    0 0 0
    //    0 0 0 

    Testsimulation->dynymic_gridsize(*Testgrid);
    //Expected new upper Row

    EXPECT_EQ(3, Testgrid->size_col());
    EXPECT_EQ(4, Testgrid->size_row());
}

TEST_F(GridTest, ThirdCheck) {
    
    Testgrid->setCell(0,0,1);
    Testgrid->setCell(1,0,1);
    Testgrid->setCell(2,0,1);
    Testgrid->setCell(0,1,1);
    Testgrid->setCell(0,2,1);
    //Checking  Matrix:
    //    1 1 1
    //    1 0 0
    //    1 0 0 

    Testsimulation->dynymic_gridsize(*Testgrid);
    //Expected new upper Row and left Col
    
    EXPECT_EQ(4, Testgrid->size_col());
    EXPECT_EQ(4, Testgrid->size_row());
}

TEST_F(GridTest, ForthCheck) {
    
    Testgrid->setCell(0,0,1);
    Testgrid->setCell(1,0,1);
    Testgrid->setCell(2,0,1);
    Testgrid->setCell(0,1,1);
    Testgrid->setCell(0,2,1);
    Testgrid->setCell(2,1,1);
    Testgrid->setCell(2,2,1);
    //Checking  Matrix:
    //    1 1 1
    //    1 0 0
    //    1 1 1 

    Testsimulation->dynymic_gridsize(*Testgrid);
    //Expected one additional col and two additional rows
    
    EXPECT_EQ(4, Testgrid->size_col());
    EXPECT_EQ(5, Testgrid->size_row());
}


TEST_F(GridTest, FifthCheck) {
    
    Testgrid->setCell(0,0,1);
    Testgrid->setCell(1,0,1);
    Testgrid->setCell(2,0,1);
    Testgrid->setCell(1,2,1);
    Testgrid->setCell(0,1,1);
    Testgrid->setCell(0,2,1);
    Testgrid->setCell(2,1,1);
    Testgrid->setCell(2,2,1);
    //Checking  Matrix:
    //    1 1 1
    //    1 0 1
    //    1 1 1 

    Testsimulation->dynymic_gridsize(*Testgrid);
    //Expected one additional col and two additional rows
    
    EXPECT_EQ(5, Testgrid->size_col());
    EXPECT_EQ(5, Testgrid->size_row());
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
