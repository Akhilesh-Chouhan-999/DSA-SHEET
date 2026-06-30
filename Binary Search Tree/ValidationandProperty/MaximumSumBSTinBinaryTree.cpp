#include <bits/stdc++.h>
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

    struct NodeInfo {

        bool isBST;
        int maxVal;
        int minVal;
        int sum;
    };
    int maxSum = 0;

    NodeInfo findMaxSumBST(TreeNode* root) {

        if(!root) {

            return {true, INT_MIN, INT_MAX, 0};
        }

        NodeInfo left = findMaxSumBST(root->left);
        NodeInfo right = findMaxSumBST(root->right);

        if(left.isBST && right.isBST && (left.maxVal < root->val && root->val < right.minVal)) {

            int currSum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, currSum);

            return {true,  max(root->val, right.maxVal), min(root->val, left.minVal), currSum};
        }

        return {false, INT_MAX, INT_MIN, 0};
    }



    int maxSumBST(TreeNode* root) {

        findMaxSumBST(root);
        return maxSum;
    }
};

int main() {
    // Example Tree:
    //
    //         1
    //        / \
    //       4   3
    //      / \   \
    //     2   4   5
    //            / \
    //           4   6
    //
    // Expected Answer: 18

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    Solution obj;
    cout << obj.maxSumBST(root) << endl;

    return 0;
}