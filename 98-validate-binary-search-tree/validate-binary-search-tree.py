# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, low, high):
            if root.val < low or root.val > high:
                return False
            res = True
            if root.left:
                res = res and dfs(root.left, low, root.val - 1) 
            if root.right:
                res = res and dfs(root.right, root.val + 1, high)
            return res
            
        return dfs(root, float('-inf'), float('inf'))