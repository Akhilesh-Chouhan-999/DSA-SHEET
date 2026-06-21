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

    vector<vector<int>> levelOrder(TreeNode* root) {


        vector<vector<int>> result;
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()) {

            int size = que.size();
            vector<int> temp;

            for(int i = 0; i < size; i ++) {

                TreeNode* node = que.front();
                que.pop();

                temp.push_back(node->val);

                if(node->left) {

                    que.push(node->left);
                }

                if(node->right) {

                    que.push(node->right);
                }
            }

            result.push_back(temp);
        }

        return result;
    }
};

int main() {

    /*
              3
            /   \
           9     20
                /  \
               15   7

    Expected Output:
    [
      [3],
      [9,20],
      [15,7]
    ]
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.levelOrder(root);

    for(auto &level : ans) {

        for(int node : level) {

            cout << node << " ";
        }

        cout << endl;
    }

    return 0;
}