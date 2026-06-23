#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 **/



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
    vector<vector<int>> result;
    void solve(TreeNode* root, int targetSum, int currSum, vector<int>& path) {

        if(!root) {

            return;
        }

        currSum += root->val;
        path.push_back(root->val);


        if(!root->left && !root->right && currSum == targetSum) {

            result.push_back(path);
            path.pop_back();
            return;
        }


        solve(root->left, targetSum, currSum, path);
        solve(root->right, targetSum, currSum, path);

        path.pop_back();

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(!root) {

            return {};
        }

        vector<int> temp;
        solve(root, targetSum, 0, temp);


        return result;
    }
};

int main() {
    // Example Tree:
    //         5
    //       /   \
    //      4     8
    //     /     / \
    //    11    13  4

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);

    int targetSum = 22;

    Solution obj;
    vector<vector<int>> ans = obj.pathSum(root, targetSum);

    // Printing answer
    for (auto &path : ans) {
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

