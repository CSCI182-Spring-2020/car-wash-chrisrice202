#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Node.h"
#include "SimpleQueue.h"

#define WASH_TIME 3

using namespace std;

int main()
{
    srand(time(NULL));   
    int inputHours, inputPercentage, chance, carNum = 0;
    int secondsPassed = 0;
    int carwash = 180, carsWashed = 1;
    int waitTime = 0;
    SimpleQueue carQueue;
    bool isOccupied = false;

    cout << "Please Enter the Number of Hours to Simulate: ";
    cin >> inputHours;
    cout << "Please Enter the Percent Chance (0-99) a car shows up every second: ";
    cin >> inputPercentage;

    while(secondsPassed < inputHours * 3600) {
        chance = rand() % 100;

        //Queue an Item on Chance
        if (chance < inputPercentage)
        {
            carQueue.QueueItem(carNum);
            carNum++;
        }

        //Put something in carWash and Keep it there
        if (carQueue.getHead() != NULL && isOccupied == false) {
            isOccupied = true;
            carsWashed++;
            waitTime += carQueue.getSecondsWaited();

            carQueue.DequeueItem();
        }
        else if (isOccupied == true) {
            carwash--;
        }

        //Open back up carwash
        if (carwash == 0) {
            isOccupied = false;
            carwash = 180;
        }

        carQueue.IncrimentList();
        secondsPassed++;
    }

    cout << endl << endl;
    cout << "Cars Washed: " << carsWashed << endl;
    cout << "Average Wait Time: " << waitTime / carsWashed << endl;
    cout << "Cars in Queue at End: " << carQueue.CountList() << endl;


}

