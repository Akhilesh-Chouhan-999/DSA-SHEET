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

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int i, int j, int &index) {

        if(i > j) {

            return NULL;
        }

        int node = preorder[index++];

        int nodeIdx = i;

        for(int k = i; k <= j; k++) {

            if(inorder[k] == node) {

                nodeIdx = k;
                break;
            }
        }

        TreeNode *root = new TreeNode(node);

        root->left  = dfs(preorder, inorder, i, nodeIdx - 1, index);
        root->right = dfs(preorder, inorder, nodeIdx + 1, j, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int index = 0;

        return dfs(preorder, inorder, 0, inorder.size() - 1, index);
    }
};

void preorderTraversal(TreeNode* root) {
    if(root == NULL) return;

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {

    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7, 8};
    vector<int> inorder  = {4, 2, 5, 1, 6, 3, 8, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Preorder of constructed tree: ";
    preorderTraversal(root);

    return 0;
}