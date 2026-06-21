#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {

            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution obj;

    // Test Case 1: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    ListNode* ans1 = obj.reverseList(head1);
    printList(ans1);

    // Test Case 2: 1 -> 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    ListNode* ans2 = obj.reverseList(head2);
    printList(ans2);

    // Test Case 3: Single Node
    ListNode* head3 = new ListNode(10);

    ListNode* ans3 = obj.reverseList(head3);
    printList(ans3);

    // Test Case 4: Empty List
    ListNode* head4 = nullptr;

    ListNode* ans4 = obj.reverseList(head4);
    printList(ans4);

    return 0;
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/