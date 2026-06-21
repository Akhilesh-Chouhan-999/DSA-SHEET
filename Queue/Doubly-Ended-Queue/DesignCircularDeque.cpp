#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> vec;
    int currSize;
    int capacity;
    int front;
    int rear;

    MyCircularDeque(int k) {

        vec.resize(k, 0);
        capacity = k;
        front = 0;
        rear = -1;
        currSize = 0;
    }
    
    bool insertFront(int value) {

        if(currSize == capacity) {

            return false;
        }

        if(currSize == 0) {

            front = rear = 0;
        }
        else {

            front = (front - 1 + capacity) % capacity;
        }

        vec[front] = value;
        currSize++;

        return true;
    }
    
    bool insertLast(int value) {
        
        if(currSize == capacity) {

            return false;
        }

        if(currSize == 0) {

            front = rear = 0;
        }
        else {

            rear = (rear + 1) % capacity;
        }

        vec[rear] = value;
        currSize++;

        return true;
    }
    
    bool deleteFront() {

        if(currSize == 0) {

            return false;
        }

        currSize--;

        if(currSize == 0) {

            front = 0;
            rear = -1;
        }
        else {

            front = (front + 1) % capacity;
        }

        return true;
    }
    
    bool deleteLast() {

        if(currSize == 0) {
            return false;
        }

        currSize--;

        if(currSize == 0) {

            front = 0;
            rear = -1;
        }
        else {

            rear = (rear - 1 + capacity) % capacity;
        }

        return true;
    }
    
    int getFront() {

        if(currSize == 0) {

            return -1;
        }

        return vec[front];
    }
    
    int getRear() {
        
        if(currSize == 0) {
            return -1;
        }

        return vec[rear];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == capacity;
    }
};

void runTest(const std::vector<std::string>& operations, 
             const std::vector<std::vector<int>>& arguments) {
    
    MyCircularDeque* obj = nullptr;
    std::vector<std::string> output;

    for (size_t i = 0; i < operations.size(); ++i) {
        const std::string& op = operations[i];
        const std::vector<int>& args = arguments[i];

        if (op == "MyCircularDeque") {
            delete obj; // Clean up previous instance if any
            obj = new MyCircularDeque(args[0]);
            output.push_back("null");
        } 
        else if (op == "insertFront") {
            bool res = obj->insertFront(args[0]);
            output.push_back(res ? "true" : "false");
        } 
        else if (op == "insertLast") {
            bool res = obj->insertLast(args[0]);
            output.push_back(res ? "true" : "false");
        } 
        else if (op == "deleteFront") {
            bool res = obj->deleteFront();
            output.push_back(res ? "true" : "false");
        } 
        else if (op == "deleteLast") {
            bool res = obj->deleteLast();
            output.push_back(res ? "true" : "false");
        } 
        else if (op == "getFront") {
            int res = obj->getFront();
            output.push_back(std::to_string(res));
        } 
        else if (op == "getRear") {
            int res = obj->getRear();
            output.push_back(std::to_string(res));
        } 
        else if (op == "isEmpty") {
            bool res = obj->isEmpty();
            output.push_back(res ? "true" : "false");
        } 
        else if (op == "isFull") {
            bool res = obj->isFull();
            output.push_back(res ? "true" : "false");
        }
    }

    // Print the output in the expected format
    std::cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        std::cout << output[i];
        if (i < output.size() - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;

    delete obj;
}

int main() {
    // Test Case from your screenshot:
    // Input: ["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]
    // Args:  [,,,,,[],[],[],,[]]
    
    std::vector<std::string> operations = {
        "MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", 
        "getRear", "isFull", "deleteLast", "insertFront", "getFront"
    };

    std::vector<std::vector<int>> arguments = {
        {3}, {1}, {2}, {3}, {4}, {}, {}, {}, {4}, {}
    };

    runTest(operations, arguments);
    cout << "Expected : [null,true,true,true,false,2,true,true,true,4]" << endl;

    return 0;
}