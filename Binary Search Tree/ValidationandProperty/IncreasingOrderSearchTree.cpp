#include <iostream>
#include <queue>
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
    void inOrder(TreeNode* root, TreeNode*& curr) {
        if (!root) return;

        inOrder(root->left, curr);

        curr->right = new TreeNode(root->val);
        curr = curr->right;

        inOrder(root->right, curr);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;

        inOrder(root, curr);

        return dummy->right;
    }
};

int main() {

    // Construct BST
    //
    //        5
    //      /   \
    //     3     6
    //    / \     \
    //   2   4     8
    //  /         / \
    // 1         7   9
    //

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    Solution obj;

    TreeNode* ans = obj.increasingBST(root);

    cout << "Increasing Order BST: ";

    while (ans) {
        cout << ans->val << " ";
        ans = ans->right;
    }

    cout << endl;

    return 0;
}