/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> visited;
        TreeNode* curr = root;

        vector<int> res;

        while (!stk.empty() || curr) {
            if (curr == NULL) {
                curr = stk.top();
                stk.pop();
                continue;
            }

            if (visited.count(curr)) {
                res.push_back(curr->val);

                if (stk.empty()) break;
                curr = stk.top();
                stk.pop();

                continue;
            }

            visited.insert(curr);
            stk.push(curr);
            stk.push(curr->right);
            curr = curr->left;
        }   
        return res;
    }
};