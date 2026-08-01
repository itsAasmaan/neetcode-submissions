/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* curr = head;
        while(curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        Node* resultingHead = head->next;

        curr = head;
        while(curr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        curr = head;
        while (curr) {
            Node* newList = curr->next;
            curr->next = newList->next;

            if (curr->next != nullptr) {
                newList->next = curr->next->next;
            }

            curr = curr->next;
        }

        return resultingHead;
    }
};
