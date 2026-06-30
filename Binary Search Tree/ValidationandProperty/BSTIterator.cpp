#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right)
            pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {

    // Construct BST
    //        7
    //      /   \
    //     3     15
    //          /  \
    //         9    20

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator obj(root);

    cout << "Inorder Traversal using BSTIterator: ";

    while (obj.hasNext()) {
        cout << obj.next() << " ";
    }

    cout << endl;

    return 0;
}

/*
    Time Complexity
    *   Constructor
        Pushes the leftmost path.
        O(H)

    *   next()
        Worst case for one call: O(H)
        Amortized: O(1)

        Reason:

        Every node is pushed exactly once.
        Every node is popped exactly once.
        Total work over all N calls = O(N).
        Therefore,
        Amortized Time=O(1)
            ​

    *   hasNext()
        O(1)
        Space Complexity
        Stack stores only one root-to-leaf path.
        O(H)
        
        where H = height of the BST.

        Balanced BST → O(log N)
        Skewed BST → O(N)
*/


