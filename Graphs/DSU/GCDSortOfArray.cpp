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

        return;
    } 

    int findGCD(int a, int b) {
   
        if (a == 0)
            return b;

        return findGCD(b % a, a);
    }

    vector<int> getPrimeFactors(int n) {

        vector<int> factors;

        for(int i = 2; i * i <= n; i++) {

            if(n % i == 0) {

                factors.push_back(i);

                while(n % i == 0) {

                    n /= i;
                }
            }
        }

        if(n > 1) {

            factors.push_back(n);
        }

        return factors; 
    }

    bool gcdSort(vector<int>& nums) {

        int size = nums.size();

        vector<int> sortedNums(begin(nums), end(nums));

        int maxi = *max_element(begin(nums), end(nums));

        vector<int> parent(maxi + 1);
        vector<int> rank(maxi + 1, 0);

        for(int i = 0; i <= maxi; i++) {

            parent[i] = i;
        }

        for(int num : nums) {

            vector<int> prime = getPrimeFactors(num);

            for(int p : prime) {

                Union(p, num, parent, rank);
            }
        }

        sort(sortedNums.begin(), sortedNums.end());

        for(int i = 0; i < size; i++) {

            if(find(nums[i], parent) != find(sortedNums[i], parent)) {

                return false;
            }
        }
        
        return true;
    }
};



// --- Main Function ---
int main() {
    Solution sol;
    
    // Test Case 1: [5, 2, 6, 2] -> Expected: false
    vector<int> nums1 = {5, 2, 6, 2};
    cout << "Test 1: " << (sol.gcdSort(nums1) ? "true" : "false") << " (Expected: false)" << endl;

    // Test Case 2: [7, 21, 3] -> Expected: true
    vector<int> nums2 = {7, 21, 3};
    cout << "Test 2: " << (sol.gcdSort(nums2) ? "true" : "false") << " (Expected: true)" << endl;

    // Test Case 3: [10, 5, 9, 3, 15] -> Expected: true
    vector<int> nums3 = {10, 5, 9, 3, 15};
    cout << "Test 3: " << (sol.gcdSort(nums3) ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}


/*
    
  Time Complexity : O(N * √M * α(M)+ N log N)
  Space Complexity : O(M + N)
*/