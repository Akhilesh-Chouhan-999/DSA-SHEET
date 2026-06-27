#include <iostream>
using namespace std;


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
    TreeNode* trim(TreeNode* root, int low, int high) {

        if (!root)
            return NULL;

        if (root->val < low)
            return trim(root->right, low, high);

        if (root->val > high)
            return trim(root->left, low, high);

        root->left = trim(root->left, low, high);
        root->right = trim(root->right, low, high);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root, low, high);
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

    // Construct BST
    //
    //          3
    //        /   \
    //       0     4
    //        \
    //         2
    //        /
    //       1
    //

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);

    Solution obj;

    int low = 1;
    int high = 3;

    TreeNode* ans = obj.trimBST(root, low, high);

    cout << "Inorder after trimming: ";
    inorder(ans);

    return 0;
}

/*
    Time Complexity : O(N)
    Space Complexity : O(H)
*/