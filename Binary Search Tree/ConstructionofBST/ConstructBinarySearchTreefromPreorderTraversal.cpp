#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* built(vector<int>& preorder, int& idx, int low, int high) {

        if(idx >= preorder.size())
            return NULL;

        int key = preorder[idx];

        if(key <= low || key >= high)
            return NULL;

        TreeNode* node = new TreeNode(key);
        idx++;

        node->left = built(preorder, idx, low, key);
        node->right = built(preorder, idx, key, high);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int idx = 0;
        return built(preorder, idx, INT_MIN, INT_MAX);
    }
};

// Inorder traversal to verify BST
void inorder(TreeNode* root) {
    if(!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution obj;
    TreeNode* root = obj.bstFromPreorder(preorder);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/