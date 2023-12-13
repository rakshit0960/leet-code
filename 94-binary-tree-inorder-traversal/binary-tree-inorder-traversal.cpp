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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        
        TreeNode* curr = root;
        while (!stk.empty() || curr) {
            if (curr == NULL) {
                if (stk.empty()) break;
                res.push_back(stk.top()->val);
                curr = stk.top()->right;
                stk.pop();
                continue;
            } 

            stk.push(curr);
            curr = curr->left;
        }

        return res;
    }
};