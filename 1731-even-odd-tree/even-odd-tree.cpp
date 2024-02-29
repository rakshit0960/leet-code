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
    bool isEvenOddTree(TreeNode* root) {      
        queue<TreeNode*> q;
        int level = 0;
        int prev_val = INT_MIN;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                if (q.empty()) break;
                q.push(NULL);
                if (level % 2 == 0) prev_val = INT_MAX;
                else prev_val = INT_MIN;
                level++;
                continue;
            } 

            if (level % 2 == 0) {
                if (node->val % 2 == 0 || node->val <= prev_val) return false;
                prev_val = node->val;
            } else {
                if (node->val % 2 == 1 || node->val >= prev_val) return false;
                prev_val = node->val;
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return true;
    }
};