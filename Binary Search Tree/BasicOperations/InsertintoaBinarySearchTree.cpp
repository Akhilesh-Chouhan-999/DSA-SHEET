#include <iostream>
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
    TreeNode* insert(TreeNode* root, int val) {

        if (!root)
            return new TreeNode(val);

        if (root->val > val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    TreeNode* insertIter(TreeNode* root, int val) {

        if(!root) {

            return new TreeNode(val);
        }

        TreeNode* curr = root;

        while(true) {

            if(curr->val < val) {

                if(curr->right) {

                    curr = curr->right;
                }

                else {

                    curr->right = new TreeNode(val);
                    break;
                }
            }

            else {

                if(curr->left) {

                    curr = curr->left;
                }

                else {

                    curr->left = new TreeNode(val);
                    break;
                }
            }

        }
        
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return insertIter(root, val);
    }
};

// Inorder Traversal
void inorder(TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    Solution obj;
    TreeNode* root = nullptr;

    // Insert values
    root = obj.insertIntoBST(root, 4);
    root = obj.insertIntoBST(root, 2);
    root = obj.insertIntoBST(root, 7);
    root = obj.insertIntoBST(root, 1);
    root = obj.insertIntoBST(root, 3);
    root = obj.insertIntoBST(root, 5);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}