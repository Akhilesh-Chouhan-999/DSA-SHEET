#include<bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(!root) {

            return {};
        }

        multiset<pair<pair<int,int>, int>> mulSet;
        queue<pair<pair<int,int>, TreeNode*>> que;

        que.push({{0, 0}, root});

        while(!que.empty()) {

            int size = que.size();

            for(int i = 1; i <= size; i ++) {

                auto [row, col] = que.front().first;
                TreeNode* node = que.front().second;
                que.pop();

                mulSet.insert({{col, row}, node->val});

                if(node->left) {

                    que.push({{row + 1, col - 1}, node->left});
                }

                if(node->right) {

                    que.push({{row + 1, col + 1}, node->right});
                }
            }
        }

        vector<vector<int>> result;
        vector<int> temp;
        int prevCol = INT_MIN;

        for(auto ms : mulSet) {

            int row = ms.first.second;
            int col = ms.first.first;
            int value = ms.second;

            if(prevCol == INT_MIN || prevCol == col) {

                temp.push_back(value);
            }
            else {

                result.push_back(temp);
                temp.clear();
                temp.push_back(value);
            }

            prevCol = col;
        }

        if(!temp.empty()) {

            result.push_back(temp);
        }

        return result;
    }
};

int main() {

    /*
            3
           / \
          9  20
             / \
            15  7

    Expected:
    [[9],[3,15],[20],[7]]
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.verticalTraversal(root);

    for(auto &col : ans) {
        cout << "[ ";
        for(int x : col) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}

/*
    Time Complexity : O(n*log(n))
    Space Complexity : O(n)
*/