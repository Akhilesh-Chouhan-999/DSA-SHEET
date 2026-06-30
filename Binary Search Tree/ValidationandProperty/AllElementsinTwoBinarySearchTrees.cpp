#include <bits/stdc++.h>
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
    void pushLeft(stack<TreeNode*>& st, TreeNode* root) {

        while(!root) {

            st.push(root);
            root = root->left;
        }

        return;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {


        vector<int> result;
        stack<TreeNode*> st1, st2;

        pushLeft(st1, root1);
        pushLeft(st2, root2);

        while(!st1.empty() || !st2.empty()) {

            TreeNode* curr;

            if(st1.empty()) {

                curr = st2.top();
                st2.pop();

                result.push_back(curr->val);

                pushLeft(st2, curr->right);
            }

            else if(st2.empty()) {

                curr = st1.top();
                st1.pop();

                result.push_back(curr->val);

                pushLeft(st1, curr->right);
            }

            else if(st1.top()->val <= st2.top()->val){

                curr = st1.top();
                st1.pop();

                result.push_back(curr->val);

                pushLeft(st1, curr->right);
            }

            else {

                curr = st2.top();
                st2.pop();

                result.push_back(curr->val);

                pushLeft(st2, curr->right);
            }

        }

        return result;
    }
};

int main() {

    // Tree 1
    //
    //      2
    //     / \
    //    1   4
    //

    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    // Tree 2
    //
    //      1
    //     / \
    //    0   3
    //

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    Solution obj;

    vector<int> ans = obj.getAllElements(root1, root2);

    cout << "Merged Elements : ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}

/*
    Time Complexity : O(m + n)
    Space Complexity : O(h1 + h2)
*/