#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) {

            return NULL;
        }

        queue<Node*> que;
        que.push(root);

        while(!que.empty()) {

            int size = que.size();
            Node* nxt = NULL;
            
            for(int i = 0; i < size; i ++) {

                Node* node = que.front();
                que.pop();

                node->next = nxt;

                if(node->right) {

                    que.push(node->right);
                }


                if(node->left) {

                    que.push(node->left);
                }
                
                nxt = node;
            }
        }

        return root;
    }
};

void printLevels(Node* root) {
    Node* levelStart = root;

    while (levelStart) {
        Node* curr = levelStart;

        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << "NULL\n";
        levelStart = levelStart->left;
    }
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    root = obj.connect(root);

    printLevels(root);

    return 0;
}