#include <iostream>

using namespace std;

void transitiveClosure(int graph[6][6], int V) {
    int closure[6][6]; 
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            closure[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << closure[i][j] << " ";
        }
        cout << endl; 
    }
}

int main() {
    int graph[6][6] = {
        {0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1}
    };

    transitiveClosure(graph, 6);

    return 0;
}

