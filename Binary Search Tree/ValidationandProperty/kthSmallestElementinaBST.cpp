#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
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
    int result = INT_MAX;
    int cnt = 0;

    void inOrder(TreeNode* root, int &k) {

        if(!root || cnt >= k)
            return;

        inOrder(root->left, k);

        cnt++;

        if(cnt == k) {

            result = root->val;
            return;
        }

        inOrder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        inOrder(root, k);
        return result;
    }
};

int main() {

    /*
             5
           /   \
          3     6
         / \
        2   4
       /
      1

    Inorder : 1 2 3 4 5 6

    k = 3
    Answer = 3
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    int k = 3;

    Solution obj;

    cout << "Kth Smallest Element = "
         << obj.kthSmallest(root, k);

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/