#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {

        // Your solution here
        return 0;
    }
};

int main() {

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    int targetSum = 8;

    Solution obj;

    cout << obj.pathSum(root, targetSum);

    return 0;
}