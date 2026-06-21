#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> seq(n);
    vector<int>pos(n + 1);
    
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
        pos[seq[i]] = i;
    }

    if(seq[0] != 1) {
        cout << "No" << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {

        sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
            return pos[a] < pos[b];
        });
        
    }

    queue<int>que;
    vector<int>bfs;
    vector<bool>visited(n + 1, false);

    que.push(1);
    visited[1] = true;

    while(!que.empty()) {

        int node = que.front();
        que.pop();
        bfs.push_back(node);

        for(int nbr : adj[node]) {
            if(!visited[nbr]) {
                que.push(nbr);
                visited[nbr] = true;
            }
        }
    }

    if(bfs == seq) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}

/*
Sorting complexity is NOT:

N×NlogN

because every adjacency list does not contain N elements.

Actual complexity:

∑deg(i)log(deg(i))

And for a tree:

∑deg(i)=2(N−1)=O(N)

Therefore total sorting complexity becomes:

O(NlogN)
*/