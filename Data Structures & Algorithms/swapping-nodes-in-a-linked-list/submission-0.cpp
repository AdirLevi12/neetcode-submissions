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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        for(int i = 0; i < k-1; i++){
            curr = curr->next;
        }
        ListNode* kth_begining = curr;
        ListNode* kth_end = head;
        while(curr->next){
            curr = curr->next;
            kth_end = kth_end->next;
        }
        int tmp = kth_begining->val;
        kth_begining->val = kth_end->val;
        kth_end->val = tmp;
        return head;
    }
    // time complexity - O(N)
    // space complexity - O(1)
};
