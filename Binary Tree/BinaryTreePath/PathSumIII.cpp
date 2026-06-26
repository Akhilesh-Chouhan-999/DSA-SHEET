/*
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    int solve(TreeNode* root, int &targetSum, long long currSum) {

        if(!root) {
            return 0;
        }

        currSum += root->val;

        int cnt = 0;

        if(currSum == targetSum) {
            cnt++;
        }

        cnt += solve(root->left, targetSum, currSum);
        cnt += solve(root->right, targetSum, currSum);

        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {

        if(!root) {
            return 0;
        }

        int cnt = 0;
        cout << root->val << endl;

        cnt += solve(root, targetSum, 0);

        cnt += pathSum(root->left, targetSum);
        cnt += pathSum(root->right, targetSum);

        return cnt;
    }
};

int main() {

    // Example Tree:
    //         10
    //        /  \
    //       5   -3
    //      / \    \
    //     3   2    11
    //    / \   \
    //   3  -2   1

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

    cout << "Number of paths = "
         << obj.pathSum(root, targetSum)
         << endl;

    return 0;
}
    Time Complexity : O(n ^ 2)
    Space Complexity : O(n)
*/

#include <iostream>
#include<unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    int solve(TreeNode* root, int& targetSum, long long currSum, unordered_map<long long, int>& mpp) {

        if(!root) {

            return 0;
        }

        currSum += root->val;

        int cnt = 0;

        if(mpp.count(currSum - targetSum)) {

            cnt += mpp[currSum - targetSum];
        }

        mpp[currSum] ++;

        cnt += solve(root->left, targetSum, currSum, mpp);
        cnt += solve(root->right, targetSum, currSum, mpp);

        mpp[currSum] --;

        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {


        unordered_map<long long, int> mpp;

        mpp[0] = 1;
        return solve(root, targetSum, 0, mpp);
    }
};



int main() {

    // Example Tree:
    //         10
    //        /  \
    //       5   -3
    //      / \    \
    //     3   2    11
    //    / \   \
    //   3  -2   1

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

    cout << "Number of paths = "
         << obj.pathSum(root, targetSum)
         << endl;

    return 0;
}
/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
