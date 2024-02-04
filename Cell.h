#ifndef CELL_H
#define CELL_H

class Cell {
private:
    int _state;  // Either alive or dead
    const int _alive;
    const int _dead;
    int _neighbors;

public:
    // Constructor
    Cell(int initialState = 0);
    
    // Copy assignment operator
    Cell& operator=(const Cell& other);

    // Getter for accessing the cell state
    int getState() const;
    // Setter for modifying the cell state
    void setState(int newState);
    //Setter for random state
    void set_random_State();
    //Setter for alive neigbors
    void set_neighbors(int alive_surr);
    //Getter for alive neigbors
    int get_alive_neighbors() const;
    

    // Destructor 
    ~Cell();  
};

#endif
