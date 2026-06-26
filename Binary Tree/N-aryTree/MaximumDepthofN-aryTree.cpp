#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:

    int calDepth(Node* root) {

        int depth = 0;

        for(Node* child : root->children) {

            depth = max(depth, calDepth(child));
        } 

        return 1 + depth;
    }
    
    int maxDepth(Node* root) {

        if(root == NULL)
            return 0;

        queue<Node*> que;
        que.push(root);

        int depth = 0;

        while(!que.empty()) {

            int size = que.size();

            for(int i = 0; i < size; i++) {

                Node* node = que.front();
                que.pop();

                for(Node* child : node->children) {

                    if(child) {
                        que.push(child);
                    }
                }
            }

            depth++;
        }

        return depth;
    }
};

int main() {

    /*
                1
             /  |  \
            2   3   4
           / \
          5   6

        Depth = 3
    */

    Node* root = new Node(1);

    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    root->children.push_back(n2);
    root->children.push_back(n3);
    root->children.push_back(n4);

    n2->children.push_back(n5);
    n2->children.push_back(n6);

    Solution obj;

    cout << "Maximum Depth = " << obj.maxDepth(root) << endl;

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/