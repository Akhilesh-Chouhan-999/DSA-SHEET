#include<bits/stdc++.h>
using namespace std;

struct ListNode{

    int data;
    ListNode* next;

    ListNode(int val) {

        this->data = val;
        next = nullptr;
    }

    ListNode(int val, ListNode* nxt) {

        this->data = val;
        this->next = nxt;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0, NULL);

        ListNode* tail = dummy;

        int carry = 0;

        while(l1 || l2 || carry) {

            int sum = 0;

            if(l1 && l2) {

                sum = l1->data + l2->data + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            else if(l1) {

                sum = l1->data + carry;
                l1 = l1->next;
            }

            else if(l2) {

                sum = l2->data + carry;
                l2 = l2->next;
            }

            else if(carry) {

                sum = carry;
            }

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            carry = sum / 10;

        }

        return dummy->next;
    }
};

int main() {

    Solution obj;

    // Test Case 1: Normal Case
    // 342 + 465 = 807
    {
        ListNode* l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);

        ListNode* l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC1: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // Test Case 2: Different Lengths
    // 81 + 0 = 81
    {
        ListNode* l1 = new ListNode(1);
        l1->next = new ListNode(8);

        ListNode* l2 = new ListNode(0);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC2: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // Test Case 3: Carry at End
    // 999 + 1 = 1000
    {
        ListNode* l1 = new ListNode(9);
        l1->next = new ListNode(9);
        l1->next->next = new ListNode(9);

        ListNode* l2 = new ListNode(1);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC3: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // Test Case 4: Single Digit No Carry
    // 2 + 3 = 5
    {
        ListNode* l1 = new ListNode(2);
        ListNode* l2 = new ListNode(3);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC4: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // Test Case 5: Single Digit With Carry
    // 9 + 9 = 18
    {
        ListNode* l1 = new ListNode(9);
        ListNode* l2 = new ListNode(9);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC5: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // Test Case 6: One List Longer
    // 9999 + 1 = 10000
    {
        ListNode* l1 = new ListNode(9);
        l1->next = new ListNode(9);
        l1->next->next = new ListNode(9);
        l1->next->next->next = new ListNode(9);

        ListNode* l2 = new ListNode(1);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC6: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // Test Case 7: Both Zero
    // 0 + 0 = 0
    {
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC7: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    // Test Case 8: Middle Carry
    // 95 + 17 = 112
    {
        ListNode* l1 = new ListNode(5);
        l1->next = new ListNode(9);

        ListNode* l2 = new ListNode(7);
        l2->next = new ListNode(1);

        ListNode* ans = obj.addTwoNumbers(l1, l2);

        cout << "TC8: ";
        while(ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }

    return 0;
}


/*
    Time Complexity : O(max(m, n))
    Space Complextiy : O(1)
*/