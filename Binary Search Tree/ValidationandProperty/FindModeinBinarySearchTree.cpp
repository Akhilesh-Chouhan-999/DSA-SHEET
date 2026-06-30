
/*
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
    void postOrder(TreeNode* root, unordered_map<int, int>& mpp) {

        if(!root) {
            return;
        }

        postOrder(root->left, mpp);
        postOrder(root->right, mpp);

        mpp[root->val]++;

        return;
    }

    vector<int> findMode(TreeNode* root) {

        if(!root) {
            
            return {};
        }

        unordered_map<int, int> mpp;

        postOrder(root, mpp);

        int maxFreq = INT_MIN;

        for(pair<int, int> p : mpp) {

            maxFreq = max(maxFreq, p.second);
        }

        vector<int> result;

        for(pair<int, int> p : mpp) {

            if(p.second == maxFreq) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};

int main() {

            2
           / \
          1   2
               \
                2

        Frequencies:
        1 -> 1
        2 -> 3
        Mode = 2
  

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(2);

    Solution obj;

    vector<int> ans = obj.findMode(root);

    cout << "Mode(s): ";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


    Time Complexity : O(n)
    Space Complexity : O(n)

*/

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

    vector<int> result;
    TreeNode* prev = NULL;
    int currCnt = 0;
    int maxCnt = 0;

    void inOrder(TreeNode* root) {

        if(!root) {

            return;
        }

        inOrder(root->left);

        if(prev == NULL) {

            currCnt = 1;
        }

        else if(prev->val == root->val) {

            currCnt ++;
        }

        else {

            currCnt = 1;
        }


        if(currCnt > maxCnt) {

            maxCnt = currCnt;
            result.clear();
            result.push_back(root->val);
        }

        else if(currCnt == maxCnt) {

            result.push_back(root->val);
        }

        prev = root;

        inOrder(root->right);

        return;
    }

    vector<int> findMode(TreeNode* root) {

        inOrder(root);
        return result;
    }
};

int main() {

    /*
            2
           / \
          1   2
               \
                2

        Frequencies:
        1 -> 1
        2 -> 3
        Mode = 2
    */

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(2);

    Solution obj;

    vector<int> ans = obj.findMode(root);

    cout << "Mode(s): ";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
    Time Complexity : O(n * log(n))
    Space Complexity : O(H) 

Suppose the BST has n nodes.

Assume the current maximum frequency is f.

Let there be m values whose frequency is exactly f.

Those m values are exactly the elements stored in result.

Now think about how many nodes those modes occupy.

Each mode appears f times.

So the total number of nodes occupied by the modes is m×f

But the tree has only n nodes.

Therefore,

m×f <= n

Since m is exactly the size of result,

result.size() <= n / f

It removes n / f element.

*/