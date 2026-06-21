#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:

    vector<int> topView(Node *root) {

        queue<pair<int, Node*>> que;
        
        que.push({0, root});
        map<int, int> mpp;

        while(!que.empty()) {

            Node* node = que.front().second;
            int axis = que.front().first;
            que.pop();

            if(mpp.find(axis) == mpp.end()) {

                mpp[axis] = node->data;
            }

            if(node->left) {

                que.push({axis - 1, node->left});
            }

            if(node->right) {

                que.push({axis + 1, node->right});
            }

        }

        vector<int> result;

        for(pair<int,int> mp : mpp) {

            result.push_back(mp.second);
        }

        return result;
    }
};



int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;

    vector<int> ans = obj.topView(root);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/