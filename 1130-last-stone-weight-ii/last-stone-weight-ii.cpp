class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        const int total = accumulate(stones.begin(), stones.end(), 0ll);
        
        int dp[n + 1][total + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int t = 0; t <= total; t++) {
            dp[n][t] = abs(t - (total - t));
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int t = total; t >= 0; t--) {
                if (t + stones[i] <= total)
                    dp[i][t] = min(dp[i + 1][t + stones[i]], dp[i + 1][t]);
            }
        }

        return dp[0][0];
    }
};