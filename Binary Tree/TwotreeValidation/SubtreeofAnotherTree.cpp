#include<bits/stdc++.h>
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

    bool isSubTree = false;
    bool check(TreeNode* root, TreeNode* subRoot) {

        if(!root && !subRoot) {

            return true;
        }

        if(!root || !subRoot) {

            return false;
        }

        return root->val == subRoot->val &&
               check(root->left, subRoot->left)  &&
               check(root->right, subRoot->right);
    }

    bool solve(TreeNode* root, TreeNode* subRoot) {

        if(!root) {

            return false;
        }

        if(check(root, subRoot)) {

            return true;
        }

        return solve(root->left, subRoot) ||
               solve(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return solve(root, subRoot);
    }
};

int main() {

    /*
            3
           / \
          4   5
         / \
        1   2
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    /*
            4
           / \
          1   2
    */

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution obj;

    cout << boolalpha << obj.isSubtree(root, subRoot);

    return 0;
}

/*
    Time Complexity : O(m * n)
    Space Complexity : O(m + n)

*/