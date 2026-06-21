#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();

        sort(begin(deck), end(deck));

        vector<int> result(n);
        queue<int> que;

        for(int i = 0; i < n; i ++) {

            que.push(i);
        }

        int idx = 0;

        while(!que.empty()) {

            int topIdx = que.front();
            que.pop();

            result[topIdx] = deck[idx];
            idx ++;

            if(que.empty()) {

                break;
            }
            
            int secTopIdx = que.front();
            que.pop();

            que.push(secTopIdx);
        }

        return result;
    }
};


// Main function to run test cases
int main() {
    Solution sol;

    // Test Case 1
    vector<int> deck1 = {17, 13, 11, 2, 3, 5, 7};
    vector<int> result1 = sol.deckRevealedIncreasing(deck1);
    
    cout << "Input: [17,13,11,2,3,5,7]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ",");
    }
    cout << "]" << endl << endl;

    // Test Case 2
    vector<int> deck2 = {1, 1000};
    vector<int> result2 = sol.deckRevealedIncreasing(deck2);

    cout << "Input: [1,1000]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;

    return 0;
}