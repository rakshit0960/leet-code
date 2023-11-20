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
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        
        ListNode* middle = middleNode(head);
        ListNode* temp = middle->next;
        middle->next = NULL;
        
        while (temp) {
            stk.push(temp);
            temp = temp->next;
        }
        
        ListNode* curr = head;
        while (!stk.empty()) {
            ListNode* top = stk.top();
            top->next = curr->next;
            curr->next = top;

            curr = top->next;
            cout << top->val << " ";
            stk.pop();
        }

    }
};