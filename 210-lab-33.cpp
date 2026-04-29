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
    const int MAX_TIME = 20;

    // probabilities:
    const int PAY_PROB = 46;
    const int JOIN_PROB = 39;
    const int SWITCH_PROB = 15;

    deque<Car> lane[NUM_LANES]; 
    
    for(int i = 0; i < NUM_LANES; i++) {
        for(int j = 0; j < INITIAL_SIZE; j++) { // so initial 
            lane[i].push_back(Car());
         }
    }

    //
    cout << "Initial queue: \n";
    for(int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";
        for(auto &car : lane[i]) {
            cout << "    ";
             car.print();
            cout << endl;
        }
    }
    //int time = 1; // the time period is 20, make this a const
    
    for(int time = 1; time <= MAX_TIME; time++) {
        cout << "Time: " << time << endl;

        // go through each lane
        for(int i = 0; i < NUM_LANES; i++) { // inside this for-loop, the condition if empty and 50/50 prob
            if(lane[i].empty()) {
                int chance = rand() % 2;

                if(chance == 0) {
                    Car c;
                    lane[i].push_back(c);
                    cout << "Joined: ";
                    c.print();
                } else {
                    cout << "No action";
                }

                cout << endl;
            }

            int chance = rand() % 100;
            
            if(chance < PAY_PROB){
                Car c = lane[i].front();

                cout << "Paid:";
                c.print();
            }
        
        }

        for(int i = 0; i < NUM_LANES; i++) {
         cout << "Queue:\n";
         if(lane[i].empty()) {
            cout << "   Empty\n";

         } else {
            for(auto &car : lane[i]) {
                cout << "    ";
                car.print();
                cout << endl;

            }
        }

    }


    return 0;
}
