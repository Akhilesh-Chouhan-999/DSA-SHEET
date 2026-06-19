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

    int dfs(TreeNode* root, int diameter) {

        if(!root) {

            return 0;
        }

        int leftHeight = dfs(root->left, diameter);
        int rightHeight = dfs(root->right, diameter);

        diameter = max(diameter, 1 + leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = INT_MIN;
        
        return dfs(root, diameter);
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Diameter = "
         << obj.diameterOfBinaryTree(root);

    return 0;
}