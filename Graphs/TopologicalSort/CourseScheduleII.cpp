/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCycle = false;
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited, stack<int>& st, int u) {

        visited[u] = true;
        pathVisited[u] = true;

        for(int &v : adj[u]) {

            if(!visited[v]) {
                dfs(adj, visited, pathVisited, st, v);
            }
            else if(pathVisited[v]) {
                isCycle = true;
                return;
            }
        }

        pathVisited[u] = false;

        st.push(u);
    }

    vector<int> topoSort(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        for(vector<int>& pre : prerequisites) {

            int a = pre[0];
            int b = pre[1];
            
            adj[b].push_back(a);
        }

        vector<bool>visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);
        stack<int>st;

        for(int i = 0; i < numCourses; i ++) {

            if(!visited[i]) {
                dfs(adj, visited, pathVisited, st, i);

                if(isCycle)
                return {};
            }
        }

        vector<int> order;

        while(!st.empty()) {

            order.push_back(st.top());
            st.pop();
        }

        if(order.size() != numCourses) {
            return {};
        }

        return order;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        return topoSort(numCourses, prerequisites);
    }
};


void printVector(const vector<int>& vec) {

    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
}

int main() {
    Solution sol;

    // Test Case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test 1: Courses = " << numCourses1 << ", Prerequisites = [[1,0]]" << endl;
    vector<int> result1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Result: ";
    if (result1.empty()) cout << "[]" << endl;
    else printVector(result1);
    cout << "------------------------" << endl;

    // Test Case 2
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Test 2: Courses = " << numCourses2 << ", Prerequisites = [[1,0],[2,0],[3,1],[3,2]]" << endl;
    vector<int> result2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Result: ";
    if (result2.empty()) cout << "[]" << endl;
    else printVector(result2);
    cout << "------------------------" << endl;

    // Test Case 3 (No prerequisites)
    int numCourses3 = 1;
    vector<vector<int>> prerequisites3 = {};
    cout << "Test 3: Courses = " << numCourses3 << ", Prerequisites = []" << endl;
    vector<int> result3 = sol.findOrder(numCourses3, prerequisites3);
    cout << "Result: ";
    if (result3.empty()) cout << "[]" << endl;
    else printVector(result3);
    cout << "------------------------" << endl;

    // Test Case 4 (Cycle scenario)
    int numCourses4 = 2;
    vector<vector<int>> prerequisites4 = {{1, 0}, {0, 1}};
    cout << "Test 4: Courses = " << numCourses4 << ", Prerequisites = [[1,0],[0,1]] (Cycle)" << endl;
    vector<int> result4 = sol.findOrder(numCourses4, prerequisites4);
    cout << "Result: ";
    if (result4.empty()) cout << "[] (Cycle detected)" << endl;
    else printVector(result4);

    return 0;
}

Time Complexity : O(V + E)
Space Complexity : O(V + E)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> topoSort(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        vector<int>inDegree(numCourses, 0);

        for(vector<int>& pre : prerequisites) {

            int a = pre[0];
            int b = pre[1];
            
            adj[b].push_back(a);
            inDegree[a] ++;
        }


        queue<int>que;

        for(int i = 0; i < numCourses; i ++) {

            if(inDegree[i] == 0){
                que.push(i);
            }
        }

        vector<int>order;

        while(!que.empty()) {

            int u = que.front();
            que.pop();

            order.push_back(u);

            for(int &v : adj[u]) {

                if(--inDegree[v] == 0) {
                    que.push(v);
                }
            }

        }
        
        if(order.size() != numCourses) {
            return {};
        } 

        return order;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        return topoSort(numCourses, prerequisites);
    }
};


void printVector(const vector<int>& vec) {

    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
}

int main() {
    Solution sol;

    // Test Case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test 1: Courses = " << numCourses1 << ", Prerequisites = [[1,0]]" << endl;
    vector<int> result1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Result: ";
    if (result1.empty()) cout << "[]" << endl;
    else printVector(result1);
    cout << "------------------------" << endl;

    // Test Case 2
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Test 2: Courses = " << numCourses2 << ", Prerequisites = [[1,0],[2,0],[3,1],[3,2]]" << endl;
    vector<int> result2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Result: ";
    if (result2.empty()) cout << "[]" << endl;
    else printVector(result2);
    cout << "------------------------" << endl;

    // Test Case 3 (No prerequisites)
    int numCourses3 = 1;
    vector<vector<int>> prerequisites3 = {};
    cout << "Test 3: Courses = " << numCourses3 << ", Prerequisites = []" << endl;
    vector<int> result3 = sol.findOrder(numCourses3, prerequisites3);
    cout << "Result: ";
    if (result3.empty()) cout << "[]" << endl;
    else printVector(result3);
    cout << "------------------------" << endl;

    // Test Case 4 (Cycle scenario)
    int numCourses4 = 2;
    vector<vector<int>> prerequisites4 = {{1, 0}, {0, 1}};
    cout << "Test 4: Courses = " << numCourses4 << ", Prerequisites = [[1,0],[0,1]] (Cycle)" << endl;
    vector<int> result4 = sol.findOrder(numCourses4, prerequisites4);
    cout << "Result: ";
    if (result4.empty()) cout << "[] (Cycle detected)" << endl;
    else printVector(result4);

    return 0;
}