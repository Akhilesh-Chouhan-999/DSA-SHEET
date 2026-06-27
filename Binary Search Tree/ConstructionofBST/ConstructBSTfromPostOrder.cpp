#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* Structure of tree node */
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

    Node* ctr(vector<int>& post, int& idx, int min, int max) {

        if (idx < 0) {

            return NULL;
        }

        int key = post[idx];

        if (key <= min || key >= max) {

            return NULL;
        }

        Node* node = new Node(key);
        idx--;

        node->right = ctr(post, idx, key, max);
        node->left = ctr(post, idx, min, key);

        return node;
    }

    Node* constructTree(vector<int>& post) {

        int idx = post.size() - 1;
        
        return ctr(post, idx, INT_MIN, INT_MAX);
    }
};

// Inorder Traversal
void inorder(Node* root) {

    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root) {

    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root) {

    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    vector<int> post = {1, 7, 5, 50, 40, 10};

    Solution obj;
    Node* root = obj.constructTree(post);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}


/*
    Time Complexity : O(n)
    Space Complexity ; o(n)
*/