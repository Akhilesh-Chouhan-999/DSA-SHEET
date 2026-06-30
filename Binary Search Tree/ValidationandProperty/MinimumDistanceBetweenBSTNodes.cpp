#include <iostream>
#include<algorithm>
#include<climits>
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
    TreeNode* prev = NULL;
    int minDiff = INT_MAX;

    void inOrder(TreeNode* root) {

        if(!root)
            return;

        inOrder(root->left);

        if(prev) {

            minDiff = min(minDiff, abs(root->val - prev->val));
        }
            prev = root;

        inOrder(root->right);

        return;
    }

    int minDiffInBST(TreeNode* root) {

        inOrder(root);
        return minDiff;
    }
};

int main() {
    /*
            4
          /   \
         2     6
        / \
       1   3

    Inorder: 1 2 3 4 6
    Minimum Difference = 1
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    cout << obj.minDiffInBST(root);

    return 0;
}


/*
    Time Complexity : O(n)
    Space Complexity : O(h)
*/