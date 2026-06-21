#include<bits/stdc++.h>
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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()) {

            int size = que.size();

            for(int i = 0; i < size; i ++) {

                TreeNode* node = que.front();
                que.pop();

                if(node->left) {

                    que.push(node->left);
                }

                if(node->right) {

                    que.push(node->right);
                }

                if(i + 1 == size) {

                    result.push_back(node->val);
                }
            }
        }


        return result;
    }
};

// Main function to test the code
int main() {
    // Construct a sample binary tree:
    //       1
    //      / \
    //     2   3
    //      \   \
    //       5   4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    // Output the right side view
    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (optional in simple programs, but good practice)
    // You can add recursive delete if needed for large trees
    return 0;
}
/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/