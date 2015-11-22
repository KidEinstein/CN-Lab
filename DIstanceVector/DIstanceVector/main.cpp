//
//  main.cpp
//  DIstanceVector
//
//  Created by Anirudh Shekhawat on 22/11/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    cout << "Enter number of nodes: ";
    int numNodes;
    cin >> numNodes;
    int** m = new int*[numNodes];
    for (int i = 0; i < numNodes; i++) {
        m[i] = new int[numNodes];
    }
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            m[i][j] = 999;
            if (i == j) {
                m[i][j] = 0;
            }
        }
    }
    cout << "Enter number of edges";
    int numEdges;
    cin >> numEdges;
    cout << "Enter source, destination and cost of each edge: " << endl;
    int src, des, cost;
    for (int i = 0; i < numEdges; i++) {
        cin >> src >> des >> cost;
        m[src][des] = cost;
        m[des][src] = cost;
    }
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            for (int k = 0; k < numNodes; k++) {
                for (int l = 0; l < numNodes; l++) {
                    m[j][k] = min(m[j][k], m[j][l] + m[l][k]);
                }
            }
        }
    }
    for (int i = 0; i < numNodes; i++) {
        cout << i << "'s Distance Vector" << endl;
        for (int j = 0; j < numNodes; j++) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
