#include <iostream>
#include <climits>

using namespace std;

const int size = 12;

int findMinKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[size][size]) {
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < size; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

void primMST(int graph[size][size]) {
    int parent[size]; 
    int key[size];     
    bool mstSet[size]; 

    for (int i = 0; i < size; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;       
    parent[0] = -1;   

    for (int count = 0; count < size - 1; count++) {
        int u = findMinKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < size; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[size][size] = {
        {0, 3, 5, 4, 0, 0, 0, 5, 0, 0, 0, 0},
        {3, 0, 0, 0, 3, 6, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 2, 0, 0, 4, 0, 0, 0, 0, 0},
        {4, 0, 2, 0, 1, 0, 0, 5, 0, 0, 0, 0},
        {0, 3, 0, 1, 0, 2, 0, 0, 4, 0, 0, 0},
        {0, 6, 0, 0, 2, 0, 0, 0, 0, 5, 0, 0},
        {0, 0, 4, 0, 0, 0, 0, 3, 0, 0, 6, 0},
        {0, 0, 0, 5, 0, 0, 3, 0, 6, 0, 7, 0},
        {0, 0, 0, 0, 4, 0, 0, 6, 0, 3, 0, 5},
        {0, 0, 0, 0, 0, 5, 0, 0, 3, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 6, 7, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 0, 0, 0, 5, 9, 8, 0}
    };

    primMST(graph);

    return 0;
}
