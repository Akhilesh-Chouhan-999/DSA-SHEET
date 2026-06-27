#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:

    void inOrder(TreeNode* root, vector<int>& vec) {

        if(!root) {

            return;
        }


        inOrder(root->left, vec);

        vec.push_back(root->val);

        inOrder(root->right, vec);

        return;
    }

    TreeNode* constructBBST(vector<int>& temp, int start, int end) {

        if (start > end) {

            return NULL;
        }

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(temp[mid]);

        root->left = constructBBST(temp, start, mid - 1);
        root->right = constructBBST(temp, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> temp;

        inOrder(root, temp);

        return constructBBST(temp, 0, temp.size() - 1);
    }
};

// Insert into BST
TreeNode* insert(TreeNode* root, int val) {

    if (!root)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal
void inorder(TreeNode* root) {

    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder Traversal (to visualize balanced tree)
void preorder(TreeNode* root) {

    if (!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {

    TreeNode* root = NULL;

    // Skewed BST
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);

    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;

    Solution obj;

    TreeNode* balancedRoot = obj.balanceBST(root);

    cout << "Balanced BST (Inorder): ";
    inorder(balancedRoot);
    cout << endl;

    cout << "Balanced BST (Preorder): ";
    preorder(balancedRoot);
    cout << endl;

    return 0;
}