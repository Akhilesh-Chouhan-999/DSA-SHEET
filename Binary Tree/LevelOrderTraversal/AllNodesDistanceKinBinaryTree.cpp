#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    void parChildRel(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {

            TreeNode* node = que.front();
            que.pop();

            if(node->left) {

                parent[node->left] = node;
                que.push(node->left);
            }

            if(node->right) {

                parent[node->right] = node;
                que.push(node->right);
            }
        }

        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;
        parChildRel(root, parent);

        queue<TreeNode*> que;
        unordered_set<TreeNode*> visited;

        que.push(target);
        visited.insert(target);
        int currLevel = 0;

        while(!que.empty()) {

            int size = que.size();

            if(currLevel++ == k) {

                break;
            }

            for(int i = 0; i < size; i ++) {

                TreeNode* node = que.front();
                que.pop();

                
                if(node->left && !visited.count(node->left)) {

                    que.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)) {

                    que.push(node->right);
                    visited.insert(node->right);
                }

                if(parent.count(node) && !visited.count(parent[node])) {

                    que.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }

        }

        vector<int> result;

        while(!que.empty()) {

            result.push_back(que.front()->val);
            que.pop();
        }

        return result;
    }
};

int main() {

    /*
            3
          /   \
         5     1
        / \   / \
       6   2 0   8
          / \
         7   4

       target = 5
       k = 2

       Output: 7 4 1
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // node 5
    int k = 2;

    Solution obj;

    vector<int> ans = obj.distanceK(root, target, k);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
