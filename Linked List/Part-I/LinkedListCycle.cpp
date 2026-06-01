#include <iostream>
#include<unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                
                return true;
            }

        }

        return false;
    }
};

int main() {
    Solution obj;

    // Test Case 1: No Cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << (obj.hasCycle(head1) ? "Cycle Present" : "No Cycle") << endl;

    // Test Case 2: Cycle Exists
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);

    // Create cycle: 4 -> 2
    head2->next->next->next->next = head2->next;

    cout << (obj.hasCycle(head2) ? "Cycle Present" : "No Cycle") << endl;

    return 0;
}