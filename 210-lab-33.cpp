#include <iostream>
#include <deque>
#include <ctime>
#include <cstdlib>
#include "Car.h"
using namespace std;
// Comsc 210. Section 5068 | Martha S. Villalta | Lab 33
// Requirements: use std::deque. Use a const and init to 2 
// for init size of deque objects [ DONE! ]
// (std::deque objects of Car type)
// Use loop run until empty
// commit at milestones [1]: successfully create a std::deque & pop. 
//it w/2 Car objects.
// milestone [2]: code successfully uses a loop that runs until deque isEmpty
// Inside Loop: branch based on probabilities (rand())

int main() {
    srand(time(0));
    const int INITIAL_SIZE = 2; // will initialize starting number of deque Car objects
    deque<Car> lane; //"...which are placed in the std::deque representing the 
                // toll booth lane."

    // Now fill initial queue:
    for(int i = 0; i < INITIAL_SIZE; i++) {
        lane.push_back(Car()); // of type Car
    }

    // Now I want to display it for Milestone 1 and see initial queue
    cout << "Initial queue\n";
    
    int time = 1;
    // I need to use a loop and have it run until deque is empty
    // a for-loop for this will run until the condition is false,
    // we need to run the loop UNTIL deque is empty
    while(!lane.empty()) {
        cout << "Time:" << time; // from the sample output, I need to show what loop operation time period
        
        
        // time needs to increment. from what? forgot to add start val.
        time++;
    }

    // to display the queue: use print. Need to until empty - inside while-loop

    return 0;
}