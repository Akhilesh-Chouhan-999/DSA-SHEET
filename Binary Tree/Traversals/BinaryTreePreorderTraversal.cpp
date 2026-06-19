#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    int val;
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> result;
    void preOrder(TreeNode* root) {

        if(!root) {

            return;
        }

        result.push_back(root->val);

        preOrder(root->left);
        preOrder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        preOrder(root);

        return result;
    }
};


int main() {

    // Tree:
    //      1
    //       \
    //        2
    //       /
    //      3

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;

    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/