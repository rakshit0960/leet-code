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
        while (curr) {
            ListNode* temp = curr->next;
            ListNode* deleteNode = curr;
            int sum = 0;
            while (temp) {
                sum += temp->val;
                if (sum == 0) deleteNode = temp;
                temp = temp->next;
            }

            curr->next = deleteNode->next;
            curr = curr->next;
        }

        return dummy.next;
    }

};