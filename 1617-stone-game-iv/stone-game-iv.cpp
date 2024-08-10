class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        dp[0] = 0;
        for (int m = 1; m <= n; m++) {
            for (int i = 1; i*i <= m; i++) {
                if (dp[m - i*i] == false) {
                    dp[m] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};