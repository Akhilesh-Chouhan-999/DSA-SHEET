#include <bits/stdc++.h>
#define V 4

using namespace std;

bool dfs(int G[][V], int u, int clr, vector<int>& colors) {

    colors[u] = clr;

    for(int v = 0; v < V; v++) {

        if(G[u][v] == 0)
            continue;

        if(colors[v] == -1) {

            if(!dfs(G, v, 1 - clr, colors)) {
                return false;
            }
        }

        else if(colors[v] == clr) {
            return false;
        }
    }

    return true;
}

bool isOddCycle(int G[][V]) {

    vector<int> color(V, -1);

    for(int i = 0; i < V; i++) {

        if(color[i] == -1) {

            if(!dfs(G, i, 0, color)) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    // TEST CASE 1 : Odd Cycle Present
    int G1[][V] = {
        {0,1,1,0},
        {1,0,1,0},
        {1,1,0,0},
        {0,0,0,0}
    };

    // TEST CASE 2 : No Odd Cycle
    int G2[][V] = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0}
    };

    // TEST CASE 3 : Self Loop
    int G3[][V] = {
        {1,0,0,0},
        {0,0,1,0},
        {0,1,0,0},
        {0,0,0,0}
    };

    // TEST CASE 4 : Line Graph
    int G4[][V] = {
        {0,1,0,0},
        {1,0,1,0},
        {0,1,0,1},
        {0,0,1,0}
    };

    cout << "Test Case 1 : ";
    isOddCycle(G1)
        ? cout << "Odd cycle is present\n"
        : cout << "Odd cycle is not present\n";

    cout << "Test Case 2 : ";
    isOddCycle(G2)
        ? cout << "Odd cycle is present\n"
        : cout << "Odd cycle is not present\n";

    cout << "Test Case 3 : ";
    isOddCycle(G3)
        ? cout << "Odd cycle is present\n"
        : cout << "Odd cycle is not present\n";

    cout << "Test Case 4 : ";
    isOddCycle(G4)
        ? cout << "Odd cycle is present\n"
        : cout << "Odd cycle is not present\n";

    return 0;
}