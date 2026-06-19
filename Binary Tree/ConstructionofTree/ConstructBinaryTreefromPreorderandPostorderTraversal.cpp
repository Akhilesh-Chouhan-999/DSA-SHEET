/*
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

    int n;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int prevStart, int prevEnd, int postStart) {

        if(prevStart > prevEnd) {

            return NULL;
        }
        
        TreeNode* node = new TreeNode(preorder[prevStart]);

        if(prevStart == prevEnd) {

            return node;
        }

        int leftSubTreeRootNode = preorder[prevStart + 1];

        int j = postStart;

        while(j < n && postorder[j] != leftSubTreeRootNode) {

            j ++;
        }

        int noOfElement = j - postStart + 1;

        node->left = buildTree(preorder, postorder, prevStart + 1, prevStart + noOfElement, postStart);
        node->right = buildTree(preorder, postorder, prevStart + noOfElement + 1, prevEnd, postStart + noOfElement);


        return node;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        this->n = preorder.size();

        return buildTree(preorder, postorder, 0, n - 1, 0);
    }
};



// Inorder traversal for checking
void inorder(TreeNode* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};

    Solution obj;

    TreeNode* root = obj.constructFromPrePost(preorder, postorder);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}

    Time Complexity : O(n ^ 2)
    Space Complexity : O(n)
*/

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

    int n;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int prevStart, int prevEnd, int postStart, unordered_map<int, int>& mpp) {

        if(prevStart > prevEnd) {

            return NULL;
        }
        
        TreeNode* node = new TreeNode(preorder[prevStart]);

        if(prevStart == prevEnd) {

            return node;
        }

        int leftSubTreeRootNode = preorder[prevStart + 1];

        int j = mpp[leftSubTreeRootNode];

        int noOfElement = j - postStart + 1;

        node->left = buildTree(preorder, postorder, prevStart + 1, prevStart + noOfElement, postStart, mpp);
        node->right = buildTree(preorder, postorder, prevStart + noOfElement + 1, prevEnd, postStart + noOfElement, mpp);


        return node;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        this->n = preorder.size();

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i ++) {

            mpp[postorder[i]] = i;
        }

        return buildTree(preorder, postorder, 0, n - 1, 0, mpp);
    }
};



// Inorder traversal for checking
void inorder(TreeNode* root) {

    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};

    Solution obj;

    TreeNode* root = obj.constructFromPrePost(preorder, postorder);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}


/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/

