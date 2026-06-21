#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find(int x, vector<int>& parent) {

        if(x == parent[x]) {

            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& size, vector<int>& count) {

        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y) {

            return;
        }

        count[size[parent_x]]--;
        count[size[parent_y]]--;

        parent[parent_y] = parent_x;
        size[parent_x] += size[parent_y];
  
        count[size[parent_x]]++;
    }

    int findLatestStep(vector<int>& arr, int m) {

        int len = arr.size();

        vector<int> parent(len + 1);
        vector<int> size(len + 1, 0);
        vector<int> count(len + 1, 0);

        vector<bool> active(len + 1, false);

        for(int i = 1; i <= len; i++) {

            parent[i] = i;
        }

        int ans = -1;

        for(int i = 0; i < len; i++) {

            int pos = arr[i];

            active[pos] = true;

            size[pos] = 1;

            count[1]++;

            if(pos - 1 >= 1 && active[pos - 1]) {

                Union(pos, pos - 1, parent, size, count);
            }

            if(pos + 1 <= len && active[pos + 1]) {

                Union(pos, pos + 1, parent, size, count);
            }

            if(count[m] > 0) {

                ans = i + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    std::vector<int> arr1 = {3, 5, 1, 2, 4};
    int m1 = 4;
    std::cout << "Test 1: Latest step with length " << m1 << " is: " 
              << sol.findLatestStep(arr1, m1) << "\n";

    // Example 2
    std::vector<int> arr2 = {3, 1, 5, 4, 2};
    int m2 = 2;
    std::cout << "Test 2: Latest step with length " << m2 << " is: " 
              << sol.findLatestStep(arr2, m2) << "\n";

    // Example 3
    std::vector<int> arr3 = {1};
    int m3 = 1;
    std::cout << "Test 3: Latest step with length " << m3 << " is: " 
              << sol.findLatestStep(arr3, m3) << "\n";

    return 0;
}

/*
    Time Complexity : O(len * α(len))
    Space Complexity : O(len)
*/