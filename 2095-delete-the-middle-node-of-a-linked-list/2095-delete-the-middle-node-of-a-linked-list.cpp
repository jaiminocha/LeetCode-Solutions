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
    ListNode* middleNode(ListNode* head) {
        ListNode* faster = head->next;
        ListNode* slower = head;
        ListNode* prevSlower = NULL;
        while (faster && faster->next){
            prevSlower = slower;
            slower = slower->next;
            faster = faster->next->next;
        }
        if (faster) return slower;
        return prevSlower;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        if (head->next == NULL){
            ListNode* temp = head;
            head = NULL;
            delete temp;
            return head;
        }
        ListNode* temp = middleNode(head);
        // cout << "data: " << temp->val << "\n";
        ListNode* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        return head;
    }
};