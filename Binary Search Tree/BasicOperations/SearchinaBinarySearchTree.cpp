#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* search(TreeNode* root, int val) {

        if (!root) {
            return NULL;
        }

        if (root->val == val) {
            return root;
        }

        if (root->val > val) {
            return search(root->left, val);
        }
        else {
            return search(root->right, val);
        }
    }

    TreeNode* iterSearch(TreeNode* root, int val) {

        while (root) {

            if(root->val == val) {

                return root;
            }

            else if(root->val > val) {

                root = root->left;
            }

            else {

                root = root->right;
            }
        }
        
        return NULL;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        
        return iterSearch(root, val);
    }
};

int main() {

    // Creating the BST
    //         4
    //       /   \
    //      2     7
    //     / \
    //    1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    TreeNode* ans = obj.searchBST(root, val);

    if (ans) {
        cout << "Node found: " << ans->val << endl;
    }
    else {
        cout << "Node not found" << endl;
    }

    return 0;
}


/*
    Time Complexity : O(H) where H is the height of binary tree
    In case of balaced BST H => log2(n)
    In case of skewed BST H => n
    Space Comoplexity : O(n)
*/