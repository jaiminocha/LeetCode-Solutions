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
        // Edge case delete first node
        // Dummy Node created
        // ListNode* temp = new ListNode();
        // temp->next = head;
        ListNode*temp = head;
        ListNode* faster = temp;
        ListNode* slower = temp;
        while (n--){
            faster = faster->next;
        }
        if (faster == NULL) return head->next;
        while (faster->next){
            faster = faster->next;
            slower = slower->next;
        }
        slower->next = slower->next->next;
        
        return head;
    }
};