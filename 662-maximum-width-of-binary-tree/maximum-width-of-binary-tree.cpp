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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        long long max_idx = 0, min_idx = INT_MAX, max_width = 0, prev_min = 0;
        q.push({root, 0});
        q.push({NULL, -1});

        while (q.size()) {
            TreeNode* node = q.front().first;
            long long idx = q.front().second - prev_min;
            q.pop();

            if (!node) {
                if (q.size() == 0) break;
                q.push({NULL, -1});
                if (max_width < max_idx - min_idx + 1) max_width = max_idx - min_idx + 1;
                prev_min = min_idx;
                max_idx = 0;
                min_idx = INT_MAX;
                continue;
            }
            
            if (max_idx < idx) max_idx = idx;
            if (min_idx > idx) min_idx = idx;

            if (node->left) q.push({node->left, idx * 2});
            if (node->right) q.push({node->right, idx *  2 + 1});
        }
        cout << max_width;
        return (max_width > max_idx - min_idx + 1) ? max_width : max_idx - min_idx + 1;
    }
};