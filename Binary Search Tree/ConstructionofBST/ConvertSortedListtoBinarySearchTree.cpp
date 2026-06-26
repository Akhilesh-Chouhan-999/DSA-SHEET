/*
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBST(ListNode* head) {

        if (!head)
            return NULL;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {

            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode* node = new TreeNode(slow->val);

        if (prev)
            prev->next = NULL;

        node->left = createBST(head);
        node->right = createBST(slow->next);

        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        return createBST(head);
    }
};

// Inorder Traversal
void inorder(TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    // Create Linked List: -10 -> -3 -> 0 -> 5 -> 9
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    Solution obj;

    TreeNode* root = obj.sortedListToBST(head);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    return 0;
}

    Time Complexity : O(n * log(n))
    Space Complexity : O(log(n))
*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    ListNode* curr;

    TreeNode* createBST(int low, int high) {

        if(low > high) {

            return NULL;
        }

        int mid = low + (high - low) / 2;

        TreeNode* leftNode = createBST(low, mid - 1);

        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;

        root->left = leftNode;
        
        root->right = createBST(mid + 1, high);

        return root;
    }

    int cntNode(ListNode* head) {

        int cntNode = 0;

        ListNode* temp = head;

        while(temp) {

            cntNode ++;
            temp = temp->next;
        }

        return cntNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        int n = cntNode(head);

        curr = head;

        return createBST(0, n - 1);
    }
};

// Inorder Traversal
void inorder(TreeNode* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    // Create Linked List: -10 -> -3 -> 0 -> 5 -> 9
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    Solution obj;

    TreeNode* root = obj.sortedListToBST(head);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    return 0;
}