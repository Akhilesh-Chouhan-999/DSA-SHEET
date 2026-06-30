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

    TreeNode *prev, *first, *middle, *second;

    void inOrder(TreeNode* root) {

        if (!root) {

            return;
        }

        inOrder(root->left);

        if (prev != NULL && prev->val > root->val) {

            if (first == NULL) {

                first = prev;
                middle = root;
            }
            else {

                second = root;
            }
        }

        prev = root;   

        inOrder(root->right);
    }

    void recoverTree(TreeNode* root) {

        prev = first = middle = second = NULL;

        inOrder(root);

        if (second) {

            swap(first->val, second->val);
        }
        else {

            swap(first->val, middle->val);
        }
    }
};

void inorder(TreeNode* root) {

    if (!root) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    /*
            3
           / \
          1   4
             /
            2

        Inorder before recovery:
        1 3 2 4

        Inorder after recovery:
        1 2 3 4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before Recovery: ";
    inorder(root);
    cout << endl;

    Solution obj;
    obj.recoverTree(root);

    cout << "After Recovery: ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(h)
*/