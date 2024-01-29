#include <iostream>
using namespace std;

int main() {
    int nodes[4][4] = {{0,3,100,100},
                       {100,0,100,3},
                       {5,100,0,2}, 
                       {6,100,1,0}};
    int n = 4;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nodes[i][k] + nodes[k][j] < nodes[i][j]) {
                    nodes[i][j] = nodes[i][k] + nodes[k][j];
                }
            }
        }
        cout << "D "<< k <<endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                     cout << nodes[i][j] << " ";
                }
            cout << "\n";
        }
        cout << "\n";
    }
    
    cout << "\nShortest paths matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << nodes[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
