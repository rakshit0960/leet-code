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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;

        stk.push(root);

        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            
            if (!curr) continue;
            res.push_back(curr->val);

            stk.push(curr->right);
            stk.push(curr->left);   
        }

        return res;
        
    }
};