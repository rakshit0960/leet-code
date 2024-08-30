class Solution {
private:
    int dp[1001][2001];    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> dfs;
        const int n = piles.size();

        // base case
        for (int i = 0; i <= k; i++) {
            dp[n][i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // // filling dp table
        for (int index = n - 1; index >= 0; index--) {
            for (int j = 1; j <= k; j++) {
                int sum = 0, res = 0, m = j;
                res = max(res, dp[index + 1][m]);
                for (int coin : piles[index]) {
                    sum += coin;
                    m -= 1;
                    if (m < 0) break;
                    res = max(res, sum +  dp[index + 1][m]);
                }
                dp[index][j] = res;
            }
        }

        return dp[0][k];

    }
};