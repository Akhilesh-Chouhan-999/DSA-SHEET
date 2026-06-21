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

class Codec {
public:

    string serialize(TreeNode* root) {

        string serStr = "";
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()) {

            TreeNode* node = que.front();
            que.pop();

            if(node) {

                serStr += to_string(node->val);
                serStr += ",";

                que.push(node->left);
                que.push(node->right);
            }

            else {

                serStr += "#,";
            }
        }

        serStr.pop_back();

        return serStr;
    }

    TreeNode* deserialize(string data) {

        if(data.empty() || data[0] == '#') {

            return NULL;
        }


        stringstream ss(data) ; 
        char delimiter = ',';
        vector<string>tokens ; 
        string temp ; 


        while(getline(ss , temp , delimiter)) {
            
            tokens.push_back(temp) ; 
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> que;
        que.push(root);
        int i = 0;

        while(!que.empty()) {

            TreeNode* top = que.front();
            que.pop();

            i ++;
            if(tokens[i] != "#") {

                top->left = new TreeNode(stoi(tokens[i]));
                que.push(top->left);
            }

            i ++;
            if(tokens[i] != "#") {

                top->right = new TreeNode(stoi(tokens[i]));
                que.push(top->right);
            }
        }

        return root;
        
    }
};

void levelOrder(TreeNode* root) {

    if(!root) {
        cout << "Empty Tree\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }

    cout << endl;
}

int main() {

    /*
            1
           / \
          2   3
             / \
            4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;

    string data = ser.serialize(root);

    cout << "Serialized Data: " << data << endl;

    TreeNode* newRoot = deser.deserialize(data);

    cout << "Level Order of Deserialized Tree: ";
    levelOrder(newRoot);

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/