#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) {

            return NULL;
        }


        if ((p->val <= root->val && root->val <= q->val) ||  (q->val <= root->val && root->val <= p->val)) {

            return root;
        }

        else if(p->val < root->val && q->val < root->val) {

            return lca(root->left, p, q);
        }

        else {

            return lca(root->right, p, q);
        }

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return lca(root, p, q);
    }
};
int main() {

    // Construct the BST
    //         6
    //       /   \
    //      2     8
    //     / \   / \
    //    0   4 7   9
    //       / \
    //      3   5

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;          // Node 2
    TreeNode* q = root->left->right;   // Node 4

    Solution obj;
    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: " << ans->val << endl;

    return 0;
}
/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/