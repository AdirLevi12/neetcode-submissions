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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        while(curr){
            ListNode* tmp = curr->next;
            while(tmp->val != 0){
                curr->val += tmp->val;
                tmp = tmp->next;
            }
            if(tmp->next){
                curr->next = tmp;
            }
            else{
                curr->next = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
    // time complexity - O(N)
    // space complexity - O(1)
};
