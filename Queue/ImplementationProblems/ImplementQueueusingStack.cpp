#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:

    stack<int> ip;
    stack<int> op;
    MyQueue() {
        
    }
    
    void push(int x) {

        ip.push(x);
    }
    
    int pop() {
        
        if(op.empty()) {

            while(!ip.empty()) {

                op.push(ip.top());
                ip.pop();
            }
        }

        int ele = op.top();
        op.pop();

        return ele;
    }
    
    int peek() {

        if(op.empty()) {

            while(!ip.empty()) {

                op.push(ip.top());
                ip.pop();
            }
        }

        return op.top();
    }
    
    bool empty() {

        return op.empty() && ip.empty();
    }
};

int main() {
    
    vector<string> operations = {"MyQueue", "push", "push", "peek", "pop", "empty"};
    vector<vector<int>> arguments = {{}, {1}, {2}, {}, {}, {}};

    MyQueue* myQueue = nullptr;

    cout << "Output: [";

    for (int i = 0; i < operations.size(); i++) {

        if (i > 0) cout << ", ";

        string op = operations[i];

        if (op == "MyQueue") {
            myQueue = new MyQueue();
            cout << "null";
        }
        else if (op == "push") {
            myQueue->push(arguments[i][0]);
            cout << "null";
        }
        else if (op == "peek") {
            cout << myQueue->peek();
        }
        else if (op == "pop") {
            cout << myQueue->pop();
        }
        else if (op == "empty") {
            cout << (myQueue->empty() ? "true" : "false");
        }
    }

    cout << "]" << endl;

    delete myQueue;

    return 0;
}