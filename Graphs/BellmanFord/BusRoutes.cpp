#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target) {
            return 0;
        }

        // stop -> routes containing that stop
        unordered_map<int, vector<int>> adj;

        for(int route = 0; route < routes.size(); route++) {

            for(int stop : routes[route]) {

                adj[stop].push_back(route);
            }
        }

        queue<int> que;

        vector<bool> routeVisited(routes.size(), false);

        for(int route : adj[source]) {

            que.push(route);
            routeVisited[route] = true;
        }

        int busesTaken = 1;

        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                int currRoute = que.front();
                que.pop();

                for(int stop : routes[currRoute]) {

                    if(stop == target) {
                        return busesTaken;
                    }

                    for(int nextRoute : adj[stop]) {

                        if(routeVisited[nextRoute]) {
                            continue;
                        }

                        routeVisited[nextRoute] = true;
                        que.push(nextRoute);
                    }
                }
            }

            busesTaken++;
        }

        return -1;
    }
};

int main() {

    Solution solution;

    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7}
    };

    int source = 1;
    int target = 6;

    cout << solution.numBusesToDestination(routes, source, target);

    return 0;
}