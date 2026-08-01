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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode* reverseHead = reverseList(head);

        if (n == 1) {
            ListNode* temp = reverseHead;
            reverseHead = reverseHead->next;
            delete temp;
        } else {
            ListNode* curr = reverseHead;
            n -= 1;
            while(--n) {
                curr = curr->next;
            }

            if (curr && curr->next) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
        }

        head = reverseList(reverseHead);
        return head;  
    } 
};
