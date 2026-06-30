#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool isValid(TreeNode* root, long long low, long long high) {

        if (!root) {
            return true;
        }

        int key = root->val;

        if (low >= key || key >= high) {
            return false;
        }

        return isValid(root->left, low, key) &&
               isValid(root->right, key, high);
    }

    bool isValidBST(TreeNode* root) {
        
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {

    // Constructing the following BST:
    //
    //         5
    //       /   \
    //      3     7
    //     / \   / \
    //    2   4 6   8
    //

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Valid BST\n";
    else
        cout << "Invalid BST\n";

    return 0;
}


/*
    Time Complexity : O(n)
    Space Complexity : O(h)
*/