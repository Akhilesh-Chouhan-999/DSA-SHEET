#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:


    queue<int> que;

    MyStack() {
        
    }
    
    void push(int x) {
        
        int size = que.size();

        que.push(x);

        for(int i = 0; i < size; i ++) {

            que.push(que.front());
            que.pop();
        }

        return;
    }
    
    int pop() {

        int element = que.front();
        que.pop();

        return element;
    }
    
    int top() {

        return que.front();
    }
    
    bool empty() {
        
        return que.empty();
    }
};


int main() {
    // Create an instance of MyStack
    MyStack myStack;

    // Example 1 from the problem description
    // Input: ["MyStack", "push", "push", "top", "pop", "empty"]
    // Args:   [],      ,    ,    [],     [],      []
    
    cout << "Running Example 1:" << endl;

    myStack.push(1);
    myStack.push(2);

    int topVal = myStack.top();
    cout << "top(): " << topVal << " (Expected: 2)" << endl;

    int popVal = myStack.pop();
    cout << "pop(): " << popVal << " (Expected: 2)" << endl;

    bool isEmpty = myStack.empty();
    cout << "empty(): " << (isEmpty ? "false" : "true") << " (Expected: false)" << endl;

    cout << "\nRunning a custom test:" << endl;
    
    // Custom test: Push 10, 20, 30
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Pop should return 30, then 20, then 10
    cout << "pop(): " << myStack.pop() << " (Expected: 30)" << endl;
    cout << "pop(): " << myStack.pop() << " (Expected: 20)" << endl;
    cout << "top(): " << myStack.top() << " (Expected: 10)" << endl;
    cout << "empty(): " << (myStack.empty() ? "true" : "false") << " (Expected: false)" << endl;
    
    myStack.pop(); // Remove 10
    cout << "empty(): " << (myStack.empty() ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}