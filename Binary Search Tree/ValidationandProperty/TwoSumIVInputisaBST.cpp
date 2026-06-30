#include <iostream>
#include <unordered_map>
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
    bool result = false;

    void inOrder(TreeNode* root, int target, unordered_map<int, int>& mpp) {
        if (!root)
            return;

        inOrder(root->left, target, mpp);

        if (mpp.count(target - root->val))
            result = true;

        mpp[root->val]++;

        inOrder(root->right, target, mpp);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mpp;
        inOrder(root, k, mpp);
        return result;
    }
};

int main() {

    // Construct BST
    //
    //        5
    //      /   \
    //     3     6
    //    / \     \
    //   2   4     7
    //

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    Solution obj;

    int k = 9;

    if (obj.findTarget(root, k))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}