#include <iostream>
#include <fstream>
#include <vector>

void readPatternFromFile(const std::string& filename, std::vector<std::vector<int>>& pattern) {
    int counter_width = 0;
    int counter_height = 1;
    char ch;

    std::ifstream input_file(filename, std::ios::in);
    if (!input_file) {
        std::cout << "No such file";
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


void printPattern(const std::vector<std::vector<int>>& pattern) {
    for (const auto& row : pattern) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl; 
}


void createnextPattern(const std::vector<std::vector<int>>& pattern){
    std::vector<std::vector<int>> nextpattern;
    nextpattern = pattern;


   for (int i = 0; i < pattern.size(); i++) /////switch to row and colum length later!
    { 
        for (int j = 0; j < pattern[i].size(); j++) 
        {   int alive_neighbor = 0;
            int current_cell = pattern[i][j];

            if (i>0 && j>0 && pattern[i-1][j-1] == 1) alive_neighbor += 1;
            if (i>0 && pattern[i-1][j] == 1) alive_neighbor += 1;
            if (i>0 && j<pattern.size() && pattern[i-1][j+1] == 1) alive_neighbor += 1;

            if (j>0 && pattern[i][j-1] == 1) alive_neighbor += 1;
            if (j<pattern.size() && pattern[i][j+1] == 1) alive_neighbor += 1;

            if (i<pattern.size()-1 && j>0 && pattern[i+1][j-1] == 1) alive_neighbor += 1;
            if (i<pattern.size()-1 && pattern[i+1][j] == 1) alive_neighbor += 1;
            if (i<pattern.size()-1 && j<pattern.size() && pattern[i+1][j+1] == 1) alive_neighbor += 1;


            //std::cout << alive_neighbor << " "; 


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

            nextpattern[i][j] = current_cell;

        }     
        //std::cout << std::endl; 
    }

    //std::cout << std::endl;
    printPattern(nextpattern);

}

int main() {
    std::vector<std::vector<int>> gameArray;
    readPatternFromFile("Testgame.txt", gameArray);
    printPattern(gameArray);
    createnextPattern(gameArray);

    return 0;
}
