#include <iostream>
#include <deque>
#include <ctime>
#include <cstdlib>
#include "Car.h"
using namespace std;
// Comsc 210. Section 5068 | Martha S. Villalta | Lab 33 (actual 33 start)
// Add more lanes
// Switching lanes
// Probabilities: 46% = car at head of queue pays and leaves
// 39% = another car joins ; 15% = rear car will shift lane)
// 50/50 if (more sim. time, and lane is empty) a new car enters the queue/not.

int main() {
    srand(time(0));
    const int INITIAL_SIZE = 2;
    const int NUM_LANES = 4;
    deque<Car> lane[NUM_LANES]; //"...which are placed in the std::deque representing the 
                // toll booth lane."
    for(int i = 0; i < NUM_LANES; i++) {
        for(int j = 0; j < INITIAL_SIZE; j++) { // so initial 
            lane[i].push_back(Car());
         }
    }

    // Now I want to display it for Milestone 1 and see initial queue
    cout << "Initial queue: \n";
    for(int i = 0; i < NUM_LANES; i++) {
        for(auto &car : lane[i]) {
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

            cout << "Operation: Joined lane: ";
            c.print();
            cout << endl;
         }

         cout << "Queue:\n";
         if(lane.empty()) {
            cout << "   Empty\n";

         } else {
            for(auto &car : lane) {
                cout << "    ";
                car.print();
                cout << endl;

            }
         }

        // time needs to increment. from what? forgot to add start val.
        time++;
    }


    return 0;
}
