#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
public:

    void inOrder(Node* r2, unordered_set<int>& st, vector<int>& result) {

        if (!r2)
            return;

        inOrder(r2->left, st, result);

        if (st.count(r2->data) == 1)
            result.push_back(r2->data);

        inOrder(r2->right, st, result);
    }

    void dfs(Node* r1, unordered_set<int>& st) {

        if (!r1)
            return;

        st.insert(r1->data);

        dfs(r1->left, st);
        dfs(r1->right, st);
    }

    vector<int> findCommon(Node* r1, Node* r2) {

        vector<int> result;
        unordered_set<int> st;

        dfs(r1, st);
        inOrder(r2, st, result);

        return result;
    }
};

int main() {

    // Tree 1
    //         5
    //       /   \
    //      1     10
    //     / \    /
    //    0   4  7
    //          \
    //           9

    Node* r1 = new Node(5);
    r1->left = new Node(1);
    r1->right = new Node(10);

    r1->left->left = new Node(0);
    r1->left->right = new Node(4);

    r1->right->left = new Node(7);
    r1->right->left->right = new Node(9);

    // Tree 2
    //        10
    //       /  \
    //      7    20
    //     / \
    //    4   9

    Node* r2 = new Node(10);
    r2->left = new Node(7);
    r2->right = new Node(20);

    r2->left->left = new Node(4);
    r2->left->right = new Node(9);

    Solution obj;

    vector<int> ans = obj.findCommon(r1, r2);

    for (int x : ans)
        cout << x << " ";

    return 0;
}

/*
    Time Complexity : O(n + m)
    Space Complexity : O(n)
*/