class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        dp = [0] * (len(arr) + 1)
        
        for i in range(len(arr) - 1, -1, -1):
            curr = 0
            for j in range(i, min(i + k, len(arr))):
                curr = max(curr, arr[j])
                dp[i] = max(dp[i], curr * (j - i + 1) + dp[j + 1])
        
        return dp[0]
                
