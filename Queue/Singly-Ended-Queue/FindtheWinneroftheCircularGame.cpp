/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> que;

        for(int i = 1; i <= n; i ++) {

            que.push(i);
        }

        while(que.size() > 1) {

            for(int cnt = 1; cnt <= k - 1; cnt ++) {

                que.push(que.front());
                que.pop();
            }

            que.pop();

        }
        

        return que.front();
        
    }
};


int main() {
    Solution solution;

    // Test Case 1: Example from the problem
    int n1 = 5;
    int k1 = 2;
    int result1 = solution.findTheWinner(n1, k1);
    cout << "Test Case 1: n = " << n1 << ", k = " << k1 << endl;
    cout << "Winner: " << result1 << " (Expected: 3)" << endl << endl;

    // Test Case 2: Example from the problem
    int n2 = 6;
    int k2 = 5;
    int result2 = solution.findTheWinner(n2, k2);
    cout << "Test Case 2: n = " << n2 << ", k = " << k2 << endl;
    cout << "Winner: " << result2 << " (Expected: 1)" << endl << endl;

    // Test Case 3: Edge case (n=1)
    int n3 = 1;
    int k3 = 1;
    int result3 = solution.findTheWinner(n3, k3);
    cout << "Test Case 3: n = " << n3 << ", k = " << k3 << endl;
    cout << "Winner: " << result3 << " (Expected: 1)" << endl;

    return 0;
}
    Time Complexity : O(n*k) 
    Space Complexity: O(n)
*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findWin(int n, int k) {

        if(n == 1) {

            return 0;
        }

        return (findWin(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {

        return findWin(n, k) + 1;
    }
};


int main() {
    Solution solution;

    // Test Case 1: Example from the problem
    int n1 = 5;
    int k1 = 2;
    int result1 = solution.findTheWinner(n1, k1);
    cout << "Test Case 1: n = " << n1 << ", k = " << k1 << endl;
    cout << "Winner: " << result1 << " (Expected: 3)" << endl << endl;

    // Test Case 2: Example from the problem
    int n2 = 6;
    int k2 = 5;
    int result2 = solution.findTheWinner(n2, k2);
    cout << "Test Case 2: n = " << n2 << ", k = " << k2 << endl;
    cout << "Winner: " << result2 << " (Expected: 1)" << endl << endl;

    // Test Case 3: Edge case (n=1)
    int n3 = 1;
    int k3 = 1;
    int result3 = solution.findTheWinner(n3, k3);
    cout << "Test Case 3: n = " << n3 << ", k = " << k3 << endl;
    cout << "Winner: " << result3 << " (Expected: 1)" << endl;

    return 0;
}