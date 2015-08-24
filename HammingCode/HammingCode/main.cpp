//
//  main.cpp
//  HammingCode
//
//  Created by Anirudh Shekhawat on 24/08/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> getCodeWord(vector<int> dataWord) {
    vector<int> codeWord(dataWord);
    
    codeWord.insert(codeWord.begin(), 0);
    codeWord.insert(codeWord.begin() + 1, 0);
    codeWord.insert(codeWord.begin() + 3, 0);
    
    codeWord[0] = (codeWord[0] + codeWord[2] + codeWord[4] + codeWord[6]) % 2;
    codeWord[1] = (codeWord[1] + codeWord[2] + codeWord[5] + codeWord[6]) % 2;
    codeWord[3] = (codeWord[3] + codeWord[4] + codeWord[5] + codeWord[6]) % 2;
    
    return codeWord;
}

void printVector(vector<int> vector) {
    for (auto it = vector.rbegin(); it != vector.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
}

int getErrorBit(vector<int> codeWord) {
    int s0 = (codeWord[0] + codeWord[2] + codeWord[4] + codeWord[6]) % 2;
    int s1 = (codeWord[1] + codeWord[2] + codeWord[5] + codeWord[6]) % 2;
    int s2 = (codeWord[3] + codeWord[4] + codeWord[5] + codeWord[6]) % 2;
    return (s2 << 2) + (s1 << 1) + s0;
}

vector<int> readVector() {
    string numberString;
    cin >> numberString;
    vector<int> number;
    for (int i = numberString.length() - 1; i >= 0; i--) {
        number.push_back(numberString[i] - '0');
    }
    return number;
}

int main() {
    cout << "Enter data word: ";
    vector<int> dataWord = readVector();
    cout << "Data Word: ";
    printVector(dataWord);
    
    vector<int> codeWord = getCodeWord(dataWord);
    cout << "Code Word: ";
    printVector(codeWord);
    
    cout << "Enter recieved code word: ";
    vector<int> recievedCodeWord = readVector();
    cout << "Recieved Code Word: ";
    printVector(recievedCodeWord);
    
    int errorBit = getErrorBit(recievedCodeWord);
    
    if (!errorBit) {
        cout << "Transmission Successful!" << endl;
    }
    else {
        cout << "Error in transmission!" << endl;
        cout << "Error occured at bit: " << errorBit;
    }
    
    return 0;
}

