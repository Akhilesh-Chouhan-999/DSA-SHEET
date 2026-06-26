#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* findRightMost(TreeNode* root) {

        while(root->right) {

            root = root->right;
        }

        return root;
    }


    TreeNode* delNode(TreeNode* root, int key) {

        if(!root) {

            return NULL;
        }

        if(root->val < key) {

            root->right = delNode(root->right, key);
        }
        
        else if(root->val > key) {

            root->left = delNode(root->left, key);
        }

        else {

            if(!root->left && !root->right) {

                delete root;
                return NULL;
            }

            else if((!root->left && root->right) || (!root->right && root->left)) {

                TreeNode* child = root->left ? root->left : root->right;
                delete root;

                return child;
            }

            else {


                TreeNode* leftChild = root->left;

                TreeNode* predecessor = findRightMost(leftChild);
                root->val = predecessor->val;

                root->left = delNode(root->left, predecessor->val);
            }
        }

        return root;
    }
      
    TreeNode* deleteNode(TreeNode* root, int key) {

        return delNode(root, key);
    }
};

// Inorder Traversal
void inorder(TreeNode* root) {

    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    // Creating BST
    //        5
    //      /   \
    //     3     6
    //    / \     \
    //   2   4     7

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter node to delete: ";
    cin >> key;

    Solution obj;
    root = obj.deleteNode(root, key);

    cout << "BST after deletion (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
    Time Complexity : O(H) + O(H) + O(H)
    Space Complexity : O(H)
*/