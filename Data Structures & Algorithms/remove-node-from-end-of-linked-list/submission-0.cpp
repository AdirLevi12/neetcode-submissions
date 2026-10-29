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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyNode(0,head);
        ListNode* tmp = &dummyNode;
        ListNode* beforeNthNode = &dummyNode;
        for(int i = 0; i < n; i++){
            tmp = tmp->next;
        }
        while(tmp->next){
            tmp = tmp->next;
            beforeNthNode = beforeNthNode->next;
        }
        beforeNthNode->next = beforeNthNode->next->next;
        return dummyNode.next;
    }

    // time complexity O(N)
    // space complexity O(1)
};
