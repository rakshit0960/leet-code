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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* curr = &dummy;
        unordered_map<int, ListNode*> prefixSumNodes;
        int sum = 0;
        while (curr) {
            sum += curr->val;
            prefixSumNodes[sum] = curr;
            curr = curr->next;
        }

        sum = 0;
        curr = &dummy;
        while (curr) {
            sum += curr->val;
            curr->next = prefixSumNodes[sum]->next;
            curr = curr->next;
        }

        return dummy.next;
    }

};