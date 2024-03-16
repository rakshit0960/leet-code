class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);

        for (int amt = 0; amt <= amount; amt++) {
            dp[amt] = !(amt % coins[0]);
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 0; amt <= amount; amt++) {
                if (amt >= coins[i]) 
                    dp[amt] += dp[amt - coins[i]];
            }
        }

        return dp[amount];
    }
};