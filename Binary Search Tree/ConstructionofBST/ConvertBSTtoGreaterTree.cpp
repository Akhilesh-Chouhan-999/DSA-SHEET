#include <iostream>
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
    
    int sum = 0;
    TreeNode* createBST(TreeNode* root) {

        if(!root) {

            return NULL;
        }

        TreeNode* node = new TreeNode();

        node->right = createBST(root->right);

        sum += root->val;
        node->val = sum;

        node->left = createBST(root->left);
        

        return node;
    }

    TreeNode* convertBST(TreeNode* root) {

        return createBST(root);
    }
};

int main() {
    /*
            4
          /   \
         1     6
        / \   / \
       0   2 5   7
            \     \
             3     8
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(1);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    Solution obj;
    root = obj.convertBST(root);

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(H)
*/