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
    pair<pair<ListNode*,ListNode*>,int> reverse(ListNode* head, int n){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int size = 0;
        while(curr && n > 0){
            size++;
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            n--;
        }
        return {{prev,curr},size};
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0){
            return head;
        }
        pair<pair<ListNode*,ListNode*>,int> p = reverse(head, INT_MAX);
        ListNode* r_head = p.first.first;
        k = k % p.second;
        if(k == 0){
            return reverse(r_head, INT_MAX).first.first;
        }
        p = reverse(r_head,k);
        ListNode* new_head = p.first.first;
        ListNode* first_part_tail = r_head;
        ListNode* second_part_tail = p.first.second;
        p = reverse(second_part_tail, INT_MAX);
        ListNode* second_part_head = p.first.first;
        first_part_tail->next = second_part_head;
        return new_head;
    }
};