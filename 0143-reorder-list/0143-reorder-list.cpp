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
    ListNode* reverse(ListNode* &head){
        ListNode* curr = head, *prev = NULL;
        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode* faster = head, *slower = head, *mid = NULL;
        
        while (faster && faster->next){
            mid = slower;
            slower = slower->next;
            faster = faster->next->next;
        }
        
        mid->next = reverse(slower);
        ListNode* t1 = mid->next;
        mid->next = NULL;
        
        ListNode* h1 = head->next, *h2 = t1, *temp = head;
        
        t1 = head;
        bool flag = false;
        while (h1 && h2){
            if (flag) {
                temp->next = h1;
                h1 = h1->next;
            }
            else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
            //cout << temp->val << " ";
            flag = !flag;
        }
        temp->next = h2;
    }
};