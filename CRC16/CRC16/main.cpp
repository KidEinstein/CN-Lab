//
//  main.cpp
//  CRC16
//
//  Created by Anirudh Shekhawat on 18/10/15.
//  Copyright (c) 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int crc[17] = {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};

void xor1(vector<int>& a, int* b, int x) {
    for (int i = 0, j = x; i < 17; i++, j++) {
        a[j] = a[j] ^ b[i];
    }
}

bool checkCodeWord(vector<int> codeWord) {
    for (int i = 0; i < codeWord.size() - 16; i++) {
        if (codeWord[i] == 1) {
            xor1(codeWord, crc, i);
        }
    }
    for (int i = codeWord.size()-16; i < codeWord.size(); i++) {
        if (codeWord[i] == 1) {
            return false;
        }
    }
    return true;;
}

vector<int> getCodeWord(vector<int> dataWord) {
    vector<int> codeWord(dataWord.size()+16);
    
    for (int i = 0; i < dataWord.size(); i++) {
        codeWord[i] = dataWord[i];
    }
    
    for (int i = 0; i < dataWord.size(); i++) {
        if (codeWord[i] == 1) {
            xor1(codeWord, crc, i);
        }
    }
    
    for (int i = 0; i < dataWord.size(); i++) {
        codeWord[i] = dataWord[i];
    }
    
    return codeWord;
}

int main(int argc, const char * argv[]) {
    
    cout << "Enter size of dataword: ";
    int n;
    cin >> n;
    
    vector<int> dataWord(n);
    vector<int> codeWord;

    
    cout << "Enter the dataword: ";
    for (int i = 0; i < n; i++) {
        cin >> dataWord[i];
    }
    
    codeWord = getCodeWord(dataWord);
    
    cout << "Code word sent" << endl;
    for (int i = 0; i < codeWord.size(); i++) {
        cout << codeWord[i] << " ";
    }
    
    vector<int> codeWordReceived(codeWord.size());
    
    cout << "Enter code word received: ";
    for (int i = 0; i < codeWord.size(); i++) {
        cin >> codeWordReceived[i];
    }
    
    if (checkCodeWord(codeWordReceived)) {
        cout << "Transmission Successful";
    }
    else {
        cout << "Transmission Unsuccessful";
    }
    
    return 0;
}
