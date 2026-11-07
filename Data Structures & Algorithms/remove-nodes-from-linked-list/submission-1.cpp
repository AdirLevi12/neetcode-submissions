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

/*
Naive Solution:
    for each node (except from the tail) will need to do another for (while we keep the prev node of the node we check in the outside loop for remove it in case we need)
    and check if there is any grater node after this node. timp complexity O(N^2) space - O(1)

Another Solution:
    * calculate the length of the list
    * create array with the size
    * conver the list to array
    * scan the arry from the end to the begining and in each cell keep the maximum value you saw from this cell until the end (include the current cell)
    * then scan the list and the array again and list again (use dummyNode)
    * for each node we check(the curr is always in the previous node and we check the curr->next)
    we check the appropriate cell in the arry and if the maximum is the same we keep this node and if the maximum is greater from the node we check we need to remove it.
*/
