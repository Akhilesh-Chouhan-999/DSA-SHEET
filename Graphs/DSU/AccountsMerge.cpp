#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x, vector<int>& parent) {

        if(x == parent[x]) {

            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {

        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent == y_parent) {

            return;
        }

        if(rank[x_parent] > rank[y_parent]) {

            parent[y_parent] = x_parent;
        }

        else if(rank[x_parent] < rank[y_parent]) {

            parent[x_parent] = y_parent;
        }

        else {

            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }

    void initParentRank(int size) {

        parent.resize(size);
        rank.resize(size, 0);

        for(int i = 0; i < size; i++) {

            parent[i] = i;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int m = accounts.size();

        initParentRank(m);

        unordered_map<string, int> mailToNode;

        for(int i = 0; i < m; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if(mailToNode.find(mail) == mailToNode.end()) {

                    mailToNode[mail] = i;
                }

                else {

                    Union(i, mailToNode[mail], parent, rank);
                }
            }
        }

        unordered_map<int, vector<string>> adj;

        for(auto it : mailToNode) {

            string mail = it.first;
            int node = it.second;

            int parentNode = find(node, parent);

            adj[parentNode].push_back(mail);
        }

        for(auto &it : adj) {

            sort(it.second.begin(), it.second.end());
        }

        vector<vector<string>> result;

        for(auto &it : adj) {

            int node = it.first;

            vector<string> temp;

            temp.push_back(accounts[node][0]);

            for(string mail : it.second) {

                temp.push_back(mail);
            }

            result.push_back(temp);
        }

        return result;
    }
};


// Main function to test the solution
int main() {
    // Example input: List of accounts where each account has a name and emails
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };

    Solution sol;
    vector<vector<string>> mergedAccounts = sol.accountsMerge(accounts);

    // Output the results
    cout << "Merged Accounts:" << endl;
    for (const auto& account : mergedAccounts) {
        for (size_t i = 0; i < account.size(); ++i) {
            cout << account[i];
            if (i < account.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

/*

    DSU : 
    Time Complexity : O(α(n)) + O(α(n))


    Overall Time Complexity : O(M * N * α(M))
    Overall Space Complexity : O(M * N * α(M))

*/