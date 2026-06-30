/*
#include <bits/stdc++.h>
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

    void inOrder(TreeNode* root, int& low, int& high, int& result) {

        if(!root) {
            return;
        }

        inOrder(root->left, low, high, result);

        int key = root->val;

        if(low <= key && key <= high) {
            result += key;
        }

        inOrder(root->right, low, high, result);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {

        int result = 0;
        inOrder(root, low, high, result);

        return result;
    }
};

int main() {

   
        //       10
        //      /  \
        //     5    15
        //    / \     \
        //   3   7     18

        // Range = [7, 15]

        // Nodes in range:
        // 7 + 10 + 15 = 32
    

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(18);

    int low = 7;
    int high = 15;

    Solution obj;

    cout << "Range Sum = " << obj.rangeSumBST(root, low, high);

    return 0;
}


    Time Complexity : O(n)
    Space Complexity : O(n)
*/

