class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        total = sum(nums)
        if total % 2 == 1: return False

        dp = [[0] * int(total // 2 + 1) for _ in range(len(nums) + 1)]

        # base case 
        # dp[i][0] = True;
        # dp[n][i] = False if i != 0 else True
        for i in range(len(nums) + 1):
            dp[i][0] = True

        for req in range(total // 2 + 1):
            dp[n][req] = False
        
        dp[n][0] = True

        # dp[i][reqSum] = dp[i + 1][reqSum] or dp[i + 1][reqSum - nums[i]];
        for i in range(n - 1, -1, -1):
            for req in range(total // 2 + 1):
                if req - nums[i] >= 0:
                    dp[i][req] = dp[i + 1][req] or dp[i + 1][req - nums[i]]
                else:
                    dp[i][req] = dp[i + 1][req]

        return dp[0][total // 2]