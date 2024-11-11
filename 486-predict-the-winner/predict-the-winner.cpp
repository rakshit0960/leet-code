class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {  
        const int n = nums.size();
        if (n % 2 == 0) return true;
        int dp[n][n];

        for (int i = 0; i < n; i++) dp[i][i] = nums[i];

        for (int gap = 1; gap < n; gap++) {
            for (int s = 0, e = gap; e < n; s++, e++) {
                dp[s][e] = max(nums[s] - dp[s + 1][e], nums[e] - dp[s][e - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};