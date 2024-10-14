class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        function<int(int, int)> func;
        const int n = stones.size();
        const int total = accumulate(stones.begin(), stones.end(), 0);

        int dp[n][total / 2 + 1];
        memset(dp, -1, sizeof(dp));

        func = [&](int i, int sum) {
            if (i == n || sum >= total / 2) 
                return abs(sum - (total - sum));
                
            if (dp[i][sum] != -1)
                return dp[i][sum];

            return dp[i][sum] = min(func(i + 1, sum), func(i + 1, sum + stones[i]));
        };

        return func(0, 0);
    }
};