#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:

    int capacity;
    int front;
    int rear;
    int *arr;
    int currSize;

    MyCircularQueue(int k) {

        arr = new int[k];
        capacity = k;
        front = 0;
        rear = -1;
        currSize = 0;
    }

    bool enQueue(int value) {

        if(currSize == capacity) {

            return false;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        currSize++;

        return true;
    }

    bool deQueue() {

        if(currSize == 0) {
            
            return false;
        }

        front = (front + 1) % capacity;
        currSize--;

        return true;
    }

    int Front() {

        if(currSize == 0) {
            return -1;
        }

        return arr[front];
    }

    int Rear() {

        if(currSize == 0) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {

        return currSize == 0;
    }

    bool isFull() {

        return currSize == capacity;
    }
};
void printResult(const vector<string>& ops, const vector<vector<int>>& args) {

    cout << "[";
    MyCircularQueue* queue = nullptr;

    for(int i = 0; i < ops.size(); i++) {

        if(ops[i] == "MyCircularQueue") {

            queue = new MyCircularQueue(args[i][0]);
            cout << "null";
        }
        else if(ops[i] == "enQueue") {

            cout << (queue->enQueue(args[i][0]) ? "true" : "false");
        }
        else if(ops[i] == "deQueue") {

            cout << (queue->deQueue() ? "true" : "false");
        }
        else if(ops[i] == "Front") {

            cout << queue->Front();
        }
        else if(ops[i] == "Rear") {

            cout << queue->Rear();
        }
        else if(ops[i] == "isEmpty") {

            cout << (queue->isEmpty() ? "true" : "false");
        }
        else if(ops[i] == "isFull") {

            cout << (queue->isFull() ? "true" : "false");
        }

        if(i != ops.size() - 1) {
            cout << ",";
        }
    }

    cout << "]\n";

    delete queue;
}

int main() {

    vector<string> operations = {
        "MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue",
        "Rear", "isFull", "deQueue", "enQueue", "Rear"
    };

    vector<vector<int>> arguments = {
        {3}, {1}, {2}, {3}, {4},
        {}, {}, {}, {4}, {}
    };

    printResult(operations, arguments);

    return 0;
}