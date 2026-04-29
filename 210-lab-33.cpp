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

    for(int i = 0; i < INITIAL_SIZE; i++) {
        lane.push_back(Car());
    }

    // Now I want to display it for Milestone 1 and see initial queue
    cout << "Initial queue: \n";

    for(auto &car : lane) {
        cout << "    ";
        car.print();
        cout << endl;
    }
    
    int time = 1;
    
    while(!lane.empty()) {
        cout << "\nTime: " << time << " "; // from the sample output, I need to show what loop operation time period
         int chance = rand() % 100;
         // I need to add the logic for probability of joining or paying
         if(chance < 55) {
            // car pays and leaves
            Car c = lane.front();
            lane.pop_front(); // I need to print whether the car/driver paid after this operation:
            cout << "Operation: Car paid: ";
            c.print();
            cout << endl;

         } else {
            Car c;
            lane.push_back(c);
         }

         cout << "Queue:\n";
         if(lane.empty()) {
            cout << "   Empty";

         } else {
            for(auto &car : lane) {
                car.print();

            }
         }

        // time needs to increment. from what? forgot to add start val.
        time++;
    }


    return 0;
}
