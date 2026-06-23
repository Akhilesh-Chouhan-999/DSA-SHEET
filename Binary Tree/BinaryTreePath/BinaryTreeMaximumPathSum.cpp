#include <iostream>
#include<climits>
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
    int solve(TreeNode* root, int& maxSum) {

        if(!root) {

            return 0;
        }

        int leftSubTree = solve(root->left, maxSum);
        int rightSubTree = solve(root->right, maxSum);

        leftSubTree = max(0, leftSubTree);
        rightSubTree = max(0, rightSubTree);

        maxSum = max(maxSum, root->val + leftSubTree + rightSubTree);

        return root->val + leftSubTree + rightSubTree;
    }
    int maxPathSum(TreeNode* root) {

        int maxSum = INT_MIN;
        
        solve(root, maxSum);

        return maxSum;
    }
};

int main() {

    /*
            -10
           /    \
          9      20
                /  \
               15   7

       Expected Output: 42
       (15 + 20 + 7)
    */

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum = "
         << obj.maxPathSum(root) << endl;

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(H)

    If tree is balanced : H = O(log(n))
    If tree is skewed   : H = O(n)
*/