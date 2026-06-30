#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inOrder(TreeNode* root, vector<int>& in) {

        if(!root) {

            return;
        }


        inOrder(root->left, in);

        in.push_back(root->val);

        inOrder(root->right, in);

        return;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        vector<int> in;
        inOrder(root, in);

        vector<vector<int>> result;

        int i = 0;

        while(i < queries.size()) {

            int q = queries[i];

            auto it = lower_bound(begin(in), end(in), q);

            int mini = -1;
            int maxi = -1;

            // MAXI
            if(it != in.end()) {

                maxi = *it;
            }

            // MINI
            if(it == in.end()) {

                mini = in.back();
            }
            
            else if(*it == q) {

                mini = *it;
            }

            else if(it != in.begin()){

                mini = *(it - 1);
            }

            result.push_back({mini, maxi});
            i ++;
        } 

        return result;
    }
};

int main() {

    // Construct BST
    //
    //         6
    //       /   \
    //      2     13
    //     / \    / \
    //    1   4  9  15
    //              /
    //             14
    //

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(15);

    root->right->right->left = new TreeNode(14);

    vector<int> queries = {2, 5, 16};

    Solution obj;

    vector<vector<int>> ans = obj.closestNodes(root, queries);

    cout << "Answer:\n";

    for(auto &x : ans) {
        cout << "[" << x[0] << ", " << x[1] << "] ";
    }

    cout << endl;

    return 0;
}

/*
    Time Complexity : O(n + Q*log(n))
    Space Complexity : O(n)
*/