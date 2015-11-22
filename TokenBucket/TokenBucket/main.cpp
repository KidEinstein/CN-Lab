//
//  main.cpp
//  LeakyToken
//
//  Created by Anirudh Shekhawat on 21/11/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << "Enter buffer size: ";
    int bufferSize;
    cin >> bufferSize;
    cout << "Enter token rate: ";
    int tokenRate;
    cin >> tokenRate;
    cout << "Enter token bucket capacity: ";
    int bucketCapacity;
    cin >> bucketCapacity;
    int choice, numCells;
    int tokensAvailable = tokenRate;
    int bufferFilled = 0;
    while (true) {
        cout << "Is there any data to send?" << endl << "Enter 1 for yes, 0 for no";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter number of cells to send";
            cin >> numCells;
            if (numCells > bufferSize - bufferFilled) {
                cout << "Insufficient space in buffer, packet dropped" << endl;
            }
            else {
                bufferFilled += numCells;
            }
        }
        if (bufferFilled != 0) {
            if (bufferFilled > tokensAvailable) {
                cout << tokensAvailable << " cells sent" << endl;
                bufferFilled -= tokensAvailable;
                tokensAvailable = 0;
            }
            else {
                cout << bufferFilled << " cells sent" << endl;
                bufferFilled = 0;
                tokensAvailable -= bufferFilled;
            }
        }
        else {
            cout << "No cells to send" << endl;
        }
        if (tokensAvailable < bucketCapacity) {
            cout << "New tokens added to bucket" << endl;
            tokensAvailable += tokenRate;
        }
        else {
            cout << "Token bucket full, no new token added" << endl;
        }
        cout << "New values: " << endl;
        cout << "Tokens available: " << tokensAvailable << endl;
        cout << "Buffer filled: " << bufferFilled << endl;
    }
    return 0;
}
