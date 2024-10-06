class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[i][amount] till index i - 1 coins needed to make amount coins
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));
        
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        

        for (int i = 1; i <= n; i++) {
            for (int amt = 1; amt <= amount; amt++) {
                if (amt >= coins[i - 1])
                    dp[i][amt] = 1 + dp[i][amt - coins[i - 1]];

                dp[i][amt] = min(dp[i][amt], dp[i - 1][amt]);
            }
        }

        if (dp[n][amount] >= 1e9) return -1;
        else return dp[n][amount];
    }
};