#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<pair<int, int>> st;

    MinStack() {}
    
    void push(int val) {
        
        if(st.empty()) {

            st.push({val, val});
            return;
        }
        

        int minVal = st.top().second;
        st.push({val, min(val, minVal)});
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        
        return st.top().first;
    }
    
    int getMin() {

        return st.top().second;
    }
};


// Main function to test MinStack
int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "getMin() returns: " << minStack.getMin() << endl;  // Expected: -3

    minStack.pop();

    cout << "top() returns: " << minStack.top() << endl;        // Expected: 0
    cout << "getMin() returns: " << minStack.getMin() << endl;  // Expected: -2

    return 0;
}
