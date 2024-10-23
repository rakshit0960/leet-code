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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> que;
        que.push(root);
        root->val = 0;
        long long levelSum = 0;

        while (!que.empty()) {
            int size = que.size();

            long long nextLevelSum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                node->val += levelSum;
                que.pop();
                
                long long siblingSum = 0;
                if (node->left) {
                    nextLevelSum += node->left->val;
                    siblingSum += node->left->val;
                    que.push(node->left);
                }
                if (node->right) {
                    nextLevelSum += node->right->val;
                    siblingSum += node->right->val;
                    que.push(node->right);
                }
                if (node->right) node->right->val = -siblingSum;
                if (node->left) node->left->val = -siblingSum;
            }

            levelSum = nextLevelSum;
        }

        return root;
    }
};