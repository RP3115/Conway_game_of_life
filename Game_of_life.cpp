#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <filesystem>


void readPatternFromFile(const std::string& filename, std::vector<std::vector<int>>& pattern) {
    namespace fs = std::filesystem;

    // Get the current working directory
    fs::path currentPath = fs::current_path();

    // Construct the full path to the file
    fs::path filePath = currentPath / filename;

    int counter_width = 0;
    int counter_height = 1;
    char ch;

    std::ifstream input_file(filePath.string(), std::ios::in);
    if (!input_file) {
        std::cout << "No such file: " << filePath << std::endl;
        return;
    }

    while (input_file.get(ch)) {
        counter_width++;
        if (ch == '\n') {
            counter_width = 0; // Reset counter_width when a newline character is encountered
            counter_height++;
        }
    }

    // Resize the 2D vector based on counters
    pattern.resize(counter_height, std::vector<int>(counter_width, 0));

    // Reset file stream to the beginning
    input_file.clear();
    input_file.seekg(0, std::ios::beg);

    int row = 0, col = 0;

    while (input_file.get(ch)) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else {
            // Convert the character to an integer and store it in the vector
            pattern[row][col] = ch - '0';
            col++;
        }
    }
    input_file.close();
}


//This function is printing the current state of the 'Game of Life'-Grid to the terminal
void printPattern(const std::vector<std::vector<int>>& pattern) {
    for (const auto& row : pattern) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl; 
}


void createnextPattern(std::vector<std::vector<int>>& pattern){
    std::vector<std::vector<int>> nextpattern;
    nextpattern = pattern;


   for (int i = 0; i < pattern.size(); i++)          // pattern.size()== size of rows
    { 
        for (int j = 0; j < pattern[i].size(); j++)  // pattern[i].size() == size of columns
        {   int alive_neighbor = 0;
            int current_cell = pattern[i][j];

            //Counting alive cells in row above
            if (i>0 && j>0 && pattern[i-1][j-1] == 1) alive_neighbor += 1;
            if (i>0 && pattern[i-1][j] == 1) alive_neighbor += 1;
            if (i>0 && j<pattern[i].size() && pattern[i-1][j+1] == 1) alive_neighbor += 1;

            //Counting alive cells in current row   
            if (j>0 && pattern[i][j-1] == 1) alive_neighbor += 1;
            if (j<pattern[i].size() && pattern[i][j+1] == 1) alive_neighbor += 1;

            //Counting alive cells in row bellow
            if (i<pattern.size()-1 && j>0 && pattern[i+1][j-1] == 1) alive_neighbor += 1;
            if (i<pattern.size()-1 && pattern[i+1][j] == 1) alive_neighbor += 1;
            if (i<pattern.size()-1 && pattern[i].size() && pattern[i+1][j+1] == 1) alive_neighbor += 1;


            //implement the rules of game of life
            switch(current_cell) {
                case 1:
                    if(alive_neighbor == 2 || alive_neighbor == 3) current_cell = 1;
                    else current_cell = 0;
                    break;
                case 0:
                    if( alive_neighbor == 3) current_cell = 1;
                    else current_cell = 0;
                    break;
                default:
                    std::cout << "Unknown Character in 2D-Array" << std::endl;
            }

            //print array
            nextpattern[i][j] = current_cell;

        }     
        //std::cout << std::endl; 
    }

    //std::cout << std::endl;
    pattern=nextpattern;
    printPattern(nextpattern);

}

int main() {
    //Change the Textfile in the next line to Test different pattern. 
    //Currently available: "Testgame.txt", "Blinker.txt", "Pentadecathlon.txt"
    std::string testfile = "Testgame.txt";          
    std::string testing_subfolder = "Testfiles/";
    testfile = testing_subfolder + testfile;
    std::vector<std::vector<int>> gameArray;
    readPatternFromFile(testfile, gameArray);
    printPattern(gameArray);

    int counter = 0;

    while(1){

        counter ++;
        std::cout << "Timestep " << counter << ":" << std::endl;
        std::cout << std::endl;
        createnextPattern(gameArray);

        //Wait 5 seconds until next iteration
        std::this_thread::sleep_for(std::chrono::seconds(5));

    }

    return 0;
}
