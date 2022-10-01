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
    // ListNode* reverseList(ListNode* head) {
    //     if (head == NULL || head->next == NULL){
    //         return head;
    //     }
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
    //     while (curr != NULL){
    //         ListNode* front = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = front;
    //     }
    //     return prev;
    // }
    // Time Complexity : O(N)
    // Space Complexity : O(1)
  
    ListNode* helper(ListNode* head){
        if (head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* newHead = helper(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        return helper(head);
    }
};