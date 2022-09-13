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
    ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
//         if (!head) return head;
//         ListNode* nex = head;
//         bool first = true;
//         ListNode* prev = NULL, *curr = head;
//         while (nex){
//             bool flag = false;
//             for (int i = 0; i < k; i++){
//                 nex = nex->next;    
//                 if (!nex) {
//                     flag = true;
//                     break;
//                 }
//             }
//             if (flag) break;
//             // reverse the sub part of length k
//             while (curr != nex){
//                 ListNode* front = curr->next; 
//                 curr->next = prev;
//                 prev = curr;
//                 curr = front;
//             }
            
//             if (first) {
//                 head = prev;
//                 first = false;
//             }
//             while (prev->next){
//                 prev = prev->next;
//             }
//             prev->next = nex;
//         }
//         return head;
        
        ListNode* h = new ListNode(-1);
        h->next = head;
        
        ListNode* prev = h, * curr = head;
        // reverse(prev, curr, NULL);
        
        while (head){
            ListNode* till = head;
            for (int i = 0; i < k; i++){
                // if (!till && i == k - 1)  break;
                if (!till) return h->next;
                till = till->next;
            }
            reverse(prev, curr, till);
            prev = head;
            curr = head = till;
        }
        
        return h->next;
    }
    void reverse(ListNode* prev, ListNode* curr, ListNode* till){
        ListNode* p = prev, * c = curr;
        p->next = NULL;
        prev = NULL;
        while (curr != till){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        c->next = till;
        p->next = prev;
    }
};