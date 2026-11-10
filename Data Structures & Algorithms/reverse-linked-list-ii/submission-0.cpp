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
    pair<ListNode*, ListNode*> reverse(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr && k > 0){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            k--;
        }
        return {prev,curr};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        ListNode dummy(0,head);
        ListNode* prev_left = &dummy;
        for(int i = 0; i < left -1; i++){
            prev_left = prev_left->next;
        }
        ListNode* reverse_part_tail = prev_left->next;
        pair<ListNode*, ListNode*> p = reverse(prev_left->next, right-left+1);
        ListNode* reverse_part_head  = p.first;
        ListNode* head_second_part = p.second;
        prev_left->next = reverse_part_head;
        reverse_part_tail->next = head_second_part;
        return dummy.next;


    }
};