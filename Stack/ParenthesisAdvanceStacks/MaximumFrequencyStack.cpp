#include<bits/stdc++.h>
using namespace std;

class FreqStack {
public:

    int maxFreq;
    unordered_map<int, stack<int>> freqToSt;
    unordered_map<int, int> KeyToFreq;

    FreqStack() {
        
        maxFreq = 0;
    }
    
    void push(int val) {

        int freq = KeyToFreq[val];

        freqToSt[freq + 1].push(val);
        KeyToFreq[val] ++;
        maxFreq = max(maxFreq, freq + 1);
    }
    
    int pop() {

        int maxFreqEle = freqToSt[maxFreq].top();

        freqToSt[maxFreq].pop();

        KeyToFreq[maxFreqEle]--;

        if(freqToSt[maxFreq].empty()) {
            maxFreq--;
        }

        return maxFreqEle;
    }
};

int main() {
    // Test case from the submission log:
    // Operations: ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"]
    // Values:     [null,      null,,,,,,,null,null,null,null]

    FreqStack fs;
    
    cout << "Pushing elements: 5, 7, 5, 7, 4, 5" << endl;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    cout << "\nPopping elements:" << endl;
    // Expected Output: 5, 7, 5, 4
    cout << "Pop: " << fs.pop() << endl; // Expected: 5
    cout << "Pop: " << fs.pop() << endl; // Expected: 7
    cout << "Pop: " << fs.pop() << endl; // Expected: 5
    cout << "Pop: " << fs.pop() << endl; // Expected: 4

    return 0;
}