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
    pair<int, int> dfs(TreeNode* root, int depth) {
        if (!root) return {0, -1};
        pair<int, int> res = {root->val, depth};

        auto lres = dfs(root->left, depth + 1);
        if (lres.second > res.second) res = lres;

        lres = dfs(root->right, depth + 1);
        if (lres.second > res.second) res = lres;
        return res;
    }

    int findBottomLeftValue(TreeNode* root) {   
        return dfs(root, 1).first;
    }
};