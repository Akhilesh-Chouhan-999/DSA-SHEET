#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head;
        ListNode *fast = head;

        bool isCycle = false;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                isCycle = true;
                break;
            }
        }

        if(!isCycle) {

            return NULL;
        }

        slow = head;

        while(slow != fast) {

            fast = fast->next;
            slow = slow->next;
        }


        return slow;

    }
};

int main() {
    Solution obj;

    // Test Case 1: Cycle starts at node with value 2
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    head1->next->next->next->next = head1->next; // 4 -> 2

    ListNode* ans1 = obj.detectCycle(head1);
    cout << (ans1 ? ans1->val : -1) << endl;

    // Test Case 2: No cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);

    ListNode* ans2 = obj.detectCycle(head2);
    cout << (ans2 ? ans2->val : -1) << endl;

    // Test Case 3: Self loop
    ListNode* head3 = new ListNode(10);
    head3->next = head3;

    ListNode* ans3 = obj.detectCycle(head3);
    cout << (ans3 ? ans3->val : -1) << endl;

    // Test Case 4: Cycle starts at head
    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);

    head4->next->next->next = head4; // 3 -> 1

    ListNode* ans4 = obj.detectCycle(head4);
    cout << (ans4 ? ans4->val : -1) << endl;

    return 0;
}