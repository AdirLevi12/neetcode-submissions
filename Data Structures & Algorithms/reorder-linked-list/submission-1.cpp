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
ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }        
        if (prev) {
            prev->next = nullptr;
        }        
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        ListNode* mid = findMid(head);        
        ListNode* revHead = reverseList(mid);
        ListNode dummyHead;
        ListNode* tmp = &dummyHead;
        ListNode* p1 = head;
        ListNode* p2 = revHead;

        while (p1 || p2) {
            if (p1) {
                tmp->next = p1;
                p1 = p1->next;
                tmp = tmp->next;
            }
            if (p2) {
                tmp->next = p2;
                p2 = p2->next;
                tmp = tmp->next;
            }
        }
        tmp->next = nullptr;
    }
};
