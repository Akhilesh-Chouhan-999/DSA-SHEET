#include <iostream>
#include <vector>
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

    void dfs(Node* root, vector<int>& result) {

        if(!root) {

            return;
        }

        for(Node* child : root->children) {

            dfs(child, result);
        }

        result.push_back(root->val);
    }

    vector<int> postorder(Node* root) {

        vector<int> result;
        dfs(root, result);

        return result;
    }
};

int main() {

    Node* root = new Node(1);

    Node* n3 = new Node(3);
    Node* n2 = new Node(2);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    root->children = {n3, n2, n4};
    n3->children = {n5, n6};

    Solution obj;
    vector<int> ans = obj.postorder(root);

    cout << "Postorder Traversal: ";
    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/