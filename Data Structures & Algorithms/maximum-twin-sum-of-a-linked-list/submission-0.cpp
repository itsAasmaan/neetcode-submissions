/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddleNode(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        while(node) {
            ListNode* nextNode = node->next;
            node->next = prev;
            prev = node;
            node = nextNode;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* middle = findMiddleNode(head);

        ListNode* left = head;
        ListNode* right = reverseList(middle);

        int result = INT_MIN;

        while(right) {
            int sum = left->val + right->val;
            result = max(sum, result);

            left = left->next;
            right = right->next;
        }

        return result;
    }
};