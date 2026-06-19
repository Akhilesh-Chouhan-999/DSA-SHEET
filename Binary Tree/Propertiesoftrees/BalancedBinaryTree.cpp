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

    int dfs(TreeNode* root, bool &flag) {

        if(!root) {

            return 0;
        }

        int leftSubTree = dfs(root->left, flag);
        int rightSubTree = dfs(root->right, flag);

        if(abs(leftSubTree - rightSubTree) > 1) {

            flag = false;
        }

        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root) {


        bool flag = true;

        dfs(root, flag);

        return flag;
    }
};


int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if(obj.isBalanced(root))
        cout << "Balanced Tree" << endl;
    else
        cout << "Not Balanced Tree" << endl;

    return 0;
}