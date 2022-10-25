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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode* temp = head;
        while (temp && temp->val == val){
            temp = temp->next;
        }
        head = temp;
        
        ListNode* prev = head;
        while (temp){
            while (temp && temp->val == val){
                temp = temp->next;
            }
            if (prev != temp) prev->next = temp;
            prev = temp;
            if (temp) temp = temp->next;
        }
        
        return head;
    }
};