#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if (!head) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {

    // Test Case 1: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    // Test Case 2: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    // Test Case 3: Single Node
    ListNode* head3 = new ListNode(10);

    // Test Case 4: 7 -> 8
    ListNode* head4 = new ListNode(7);
    head4->next = new ListNode(8);

    // Test Case 5: Empty List
    ListNode* head5 = nullptr;

    Solution obj;

    ListNode* ans1 = obj.middleNode(head1);
    if (ans1) cout << ans1->val << endl;

    ListNode* ans2 = obj.middleNode(head2);
    if (ans2) cout << ans2->val << endl;

    ListNode* ans3 = obj.middleNode(head3);
    if (ans3) cout << ans3->val << endl;

    ListNode* ans4 = obj.middleNode(head4);
    if (ans4) cout << ans4->val << endl;

    ListNode* ans5 = obj.middleNode(head5);
    if (ans5) cout << ans5->val << endl;

    return 0;
}

/*
    Time Complexity : O(n)
    Special Complexity : O(1)
*/