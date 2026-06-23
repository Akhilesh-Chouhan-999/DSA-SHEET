#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:

    void parChildRel(Node* root, unordered_map<Node*, Node*>& parent) {

        queue<Node*> que;
        que.push(root);

        while(!que.empty()) {

            Node* node = que.front();
            que.pop();

            if(node->left) {

                parent[node->left] = node;
                que.push(node->left);
            }

            if(node->right) {

                parent[node->right] = node;
                que.push(node->right);
            }
        }

        return;
    }

    void addTargetNode(Node* root, int target, Node* &refTarget) {

        if(!root) {

            return;
        }

        if(root->data == target) {

            refTarget = root;
            return;
        }

        addTargetNode(root->left, target, refTarget);
        addTargetNode(root->right, target, refTarget);
        
        return;
    }


    int minTime(Node* root, int target) {


        Node* tar = NULL;
        addTargetNode(root, target, tar);
       
        unordered_map<Node*, Node*> parent;
        parChildRel(root, parent);

        int minTime = -1;
        queue<Node*> que;
        unordered_set<Node*> visited;

        que.push(tar);
        visited.insert(tar);
        
        while(!que.empty()) {

            int size = que.size();

            for(int i = 0; i < size; i ++) {

                Node* node = que.front();
                que.pop();

                if(node->left && !visited.count(node->left)) {

                    visited.insert(node->left);
                    que.push(node->left);
                }

                if(node->right && !visited.count(node->right)) {

                    visited.insert(node->right);
                    que.push(node->right);
                }

                if(parent.count(node) && !visited.count(parent[node])) {

                    visited.insert(parent[node]);
                    que.push(parent[node]);
                }
            }

            minTime ++;
        }

        return minTime;
    }
};

int main() {

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7

        target = 5
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;

    Solution obj;

    cout << obj.minTime(root, target);

    return 0;
}

/*
    Time Complexity : O(N)
    Space Complexity : O(N)
*/