#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) {
            return NULL;
        }
        
        unordered_map<Node*, Node*> mpp;

        for(auto it = head; it != NULL; it = it->next) {

            mpp[it] = new Node(it->val);
        }

        
        for(auto it = head; it != NULL; it = it->next) {

            mpp[it]->next = mpp[it->next];
            mpp[it]->random = mpp[it->random];
        }
        return mpp[head];
    }
};

int main() {
    
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution obj;
    Node* copiedHead = obj.copyRandomList(n1);

    for(Node* temp = copiedHead; temp != NULL; temp = temp->next) {
        cout << "Val: " << temp->val << ", Random: ";
        
        if(temp->random) {
            cout << temp->random->val;
        } else {
            cout << "NULL";
        }

        cout << endl;
    }

    return 0;
}