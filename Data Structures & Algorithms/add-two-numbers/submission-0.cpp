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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode dummyHead;
            ListNode* curr = &dummyHead;
            int carry = 0;
            while(l1 || l2 || carry != 0){
                int sum = carry;
                sum += l1 ? l1->val : 0;
                sum += l2 ? l2->val : 0;
                carry = sum / 10;
                int digit = sum % 10;
                curr-> next = new ListNode(digit);
                curr = curr->next;
                l1 = l1? l1->next : l1;
                l2 = l2? l2->next: l2;
            }
            return dummyHead.next;
        }
};