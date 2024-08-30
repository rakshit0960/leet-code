class Solution {
    int dp[10001][7][7];
    int mod = 1e9 + 7;
public:
    int distinctSequences(int n) {
        function<int(int, int, int)> dfs;

        dfs = [&] (int m, int prev, int prev_prev) {
            if (m == 0) return 1;
            if (dp[m][prev][prev_prev]) return dp[m][prev][prev_prev];
            int res = 0;
            for (int i = 1; i <= 6; i++) {
                if (i == prev || i == prev_prev) continue;
                if (__gcd(i, prev) != 1) continue;
                res = (res + dfs(m - 1, i, prev)) % mod;
            }
            return dp[m][prev][prev_prev] = res % mod;
        };


        int res = 0;
        for (int i = 1; i <= 6; i++) {
            res = (res + dfs(n - 1, i, 0)) % mod;
        }

        return res % mod;
    }
};