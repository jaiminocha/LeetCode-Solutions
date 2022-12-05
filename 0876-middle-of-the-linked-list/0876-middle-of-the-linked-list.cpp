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
        if (head == NULL){
            return head;
        }
        ListNode* faster = head->next;
        ListNode* slower = head;
        while (faster && faster->next){
            slower = slower->next;
            faster = faster->next->next;
        }
        if (faster) slower = slower->next;
        return slower;
    }
};