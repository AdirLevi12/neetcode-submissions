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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
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

    int pairSum(ListNode* head) {
        int res = INT_MIN;
        ListNode* mid = findMid(head);
        ListNode* reverse_head = reverse(mid);
        while(head && reverse_head){
            int curr_sum = head->val + reverse_head->val;
            res = max(res, curr_sum);
            head = head->next;
            reverse_head = reverse_head->next;
        }
        return res;
    }
    // time complexity - O(N);
    // space complexity - O(1);
    /*
    Naive Solution:
        * create a vector and push_back all the list value;
        * with two pointer that initial to the start and the end calculte each twin and return the max;
        time O(N) space - O(N)
    */

};