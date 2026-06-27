/*
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <sstream>

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

class Codec {
public:
    void preOrderTrav(TreeNode* root, string &data) {

        if(!root) {

            return;
        }

        data += (to_string(root->val) + ",");

        preOrderTrav(root->left, data);
        preOrderTrav(root->right, data);
    }

    string serialize(TreeNode* root) {

        if(!root) {

            return "";
        }

        
        string data = "";

        preOrderTrav(root, data);

        data.pop_back();

        return data;
    }

    TreeNode* buildTree(vector<int>& pre, int low, int high) {

        if(low > high) {

            return NULL;
        }

        if(low == high) {

            return new TreeNode(pre[low]);
        }

        TreeNode* node = new TreeNode(pre[low]);

        int idx = low + 1;

        for( ; idx <= high; idx ++) {

            if(pre[idx] > pre[low]) {

                break;
            }
        }

        node->left = buildTree(pre, low + 1, idx - 1);
        node->right = buildTree(pre, idx, high);

        return node;
    }

    TreeNode* deserialize(string data) {

        vector<int> pre;

        stringstream ss(data); 
        string token;
        char delimeter = ',';
        while(getline(ss, token, delimeter)) {

            pre.push_back(stoi(token));
        }

        return buildTree(pre, 0, pre.size() - 1);
    }
};

int main() {

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(12);

    Codec obj;

    string s = obj.serialize(root);

    cout << "Serialized: " << s << endl;

    TreeNode* newRoot = obj.deserialize(s);

    cout << "Serialized Again: " << obj.serialize(newRoot) << endl;

    return 0;
}
    Time Complexity : O(n ^ 2)
    Space Complexity : O(n)
*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <sstream>
#include<stack>

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

class Codec {
public:
    void preOrderTrav(TreeNode* root, string &data) {

        if(!root) {

            return;
        }

        data += (to_string(root->val) + ",");

        preOrderTrav(root->left, data);
        preOrderTrav(root->right, data);
    }

    string serialize(TreeNode* root) {

        if(!root) {

            return "";
        }

        
        string data = "";

        preOrderTrav(root, data);

        data.pop_back();

        return data;
    }

    TreeNode* buildTree(vector<int>& pre, int low, int high, vector<int>& nge) {

        if(low > high) {

            return NULL;
        }

        if(low == high) {

            return new TreeNode(pre[low]);
        }

        TreeNode* node = new TreeNode(pre[low]);

        int idx = nge[low];
        
        if(idx == -1) {

            idx = high + 1;
        }

        node->left = buildTree(pre, low + 1, idx - 1, nge);
        node->right = buildTree(pre, idx, high, nge);

        return node;
    }

    vector<int> calNGE(vector<int>& pre) {

        int n = pre.size();

        vector<int> nge(n, -1);
        stack<int> st;

        for(int i = n - 1; i >= 0; i --) {


            while(!st.empty() && pre[i] > pre[st.top()]) {

                st.pop();
            }

            if(!st.empty()) {

                nge[i] = st.top();
            }

            st.push(i);
        }

        return nge;
    }

    TreeNode* deserialize(string data) {

        if(data.empty()) {

            return NULL;
        }


        vector<int> pre;

        stringstream ss(data); 
        string token;
        char delimeter = ',';
        while(getline(ss, token, delimeter)) {

            pre.push_back(stoi(token));
        }


        vector<int> nge = calNGE(pre);

        return buildTree(pre, 0, pre.size() - 1, nge);
    }
};

int main() {

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(12);

    Codec obj;

    string s = obj.serialize(root);

    cout << "Serialized: " << s << endl;

    TreeNode* newRoot = obj.deserialize(s);

    cout << "Serialized Again: " << obj.serialize(newRoot) << endl;

    return 0;
}
/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/