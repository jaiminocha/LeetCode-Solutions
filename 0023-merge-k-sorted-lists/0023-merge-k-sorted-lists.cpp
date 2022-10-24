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
    ListNode* merge(vector<ListNode*>& lists){
        ListNode* head = NULL;
        int n = lists.size();
        int idx = -1, minVal = INT_MAX;
        ListNode* ans = NULL;
        
        for (int i = 0; i < n; i++){
            if (!lists[i]) {
                continue;
            }
            if (minVal >= lists[i]->val){
                minVal = lists[i]->val;
                idx = i;
            }
        }
        if (idx == -1) return NULL;
        ans = lists[idx];
        lists[idx] = lists[idx]->next;
        ans->next = merge(lists);
        return ans;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists);
    }
};