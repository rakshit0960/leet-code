class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2: return False

        halfSum = sum(nums) // 2

        dp = [[-1] * (halfSum + 1) for _ in range(len(nums))]

        def dfs(i, amt):
            if i < 0:
                return False
            if i == 0:
                return nums[0] == amt

            if dp[i][amt] != -1: 
                return dp[i][amt] 

            dp[i][amt] = dfs(i - 1, amt) or dfs(i - 1, amt - nums[i]) 

            return dp[i][amt]

        return dfs(len(nums) - 1, halfSum)