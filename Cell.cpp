#include "Cell.h"
#include <cstdlib>

Cell::Cell(int initialState) : _alive(1), _dead(0), _state(initialState) {}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        _state = other._state;
    }
    return *this;
}

int Cell::getState() const {
    return _state;
}

void Cell::setState(int newState) {
    // Ensure the value is either 0 or 1
    _state = (newState == _dead || newState == _alive) ? newState : 0;
}

void Cell::set_random_State() {
    _state = rand() % 2;
}


Cell::~Cell() {}

