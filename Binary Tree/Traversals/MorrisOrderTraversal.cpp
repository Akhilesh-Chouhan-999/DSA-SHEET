#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class MorrisOrderTraversal {
public:
    
    vector<int> inOrderMorrisTraversal(Node* node) {

        vector<int> result;
        Node* curr = node;

        while(curr != NULL) {

            if(curr -> left == NULL) {

                result.push_back(curr->data);
                curr = curr->right;
            }

            else {

                Node* leftChild = curr->left;

                while(leftChild->right != NULL) {

                    leftChild = leftChild->right;
                }
                
                leftChild->right = curr;

                Node* link = curr;
                curr = curr->left;
                link->left = NULL;
            }
        }

        return result;
    }
};
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    MorrisOrderTraversal obj;

    vector<int> ans = obj.inOrderMorrisTraversal(root);

    cout << "Inorder Traversal: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}