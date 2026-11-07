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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* reverse_head = reverse(head);
        ListNode* curr = reverse_head;
        int curr_max = -1;
        while(curr && curr->next){
            curr_max = max(curr_max, curr->val);
            if(curr->next->val < curr_max){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return reverse(reverse_head);
    }
    // time complexity - O(N)
    // space complexity - O(1)
};
