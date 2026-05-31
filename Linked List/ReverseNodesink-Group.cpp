#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* tail = head;

        for(int i = 1; i <= k - 1 && tail; i ++) {

            tail = tail->next;
        }

        if(!tail) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i = 1; i <= k; i ++) {

            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);
        return tail;
    }
};

int main() {

    Solution obj;

    // TC1: 1->2->3->4->5 , k = 2
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        ListNode* ans = obj.reverseKGroup(head, 2);

        cout << "TC1: ";
        while(ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // TC2: 1->2->3->4->5 , k = 3
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        ListNode* ans = obj.reverseKGroup(head, 3);

        cout << "TC2: ";
        while(ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // TC3: k = 1
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);

        ListNode* ans = obj.reverseKGroup(head, 1);

        cout << "TC3: ";
        while(ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // TC4: Length < k
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);

        ListNode* ans = obj.reverseKGroup(head, 3);

        cout << "TC4: ";
        while(ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // TC5: Length == k
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);

        ListNode* ans = obj.reverseKGroup(head, 3);

        cout << "TC5: ";
        while(ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // TC6: Single Node
    {
        ListNode* head = new ListNode(1);

        ListNode* ans = obj.reverseKGroup(head, 2);

        cout << "TC6: ";
        while(ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    return 0;
}

/*
    Time Complexity : O(n / k * k ) { No. of Recursive Call for group of k : (n / k) * Time for reversing a group of k }
    Space Complexity : O(n / k)
*/