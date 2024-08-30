class Solution {
    int dp[10001][7][7];
    int mod = 1e9 + 7;
public:
    int distinctSequences(int n) {
        function<int(int, int, int)> func;
        
        // base case
        for (int i = 0; i <= 6; i++) {
            for (int j = 0; j <= 6; j++) {
                dp[0][i][j] = 1;
            }
        }

        // // filling dptable
        for (int m = 1; m < n; m++) {
            for (int p = 0; p <= 6; p++) {
                for (int pp = 0; pp <= 6; pp++) {

                    int res = 0;
                    for (int i = 1; i <= 6; i++) {
                        if (i == p || i == pp) continue;
                        if (__gcd(i, p) != 1) continue;
                        res = (res + dp[m - 1][i][p]) % mod;
                    }
            
                    dp[m][p][pp] = res % mod;

                }
            }
        }

        int res = 0;
        for (int i = 1; i <= 6; i++) {
            res = (res + dp[n - 1][i][0]) % mod;
        }

        return res % mod;

        // func = [&] (int m, int prev, int prev_prev) {
        //     if (dp[m][prev][prev_prev]) return dp[m][prev][prev_prev];
        //     int res = 0;
        //     for (int i = 1; i <= 6; i++) {
        //         if (i == prev || i == prev_prev) continue;
        //         if (__gcd(i, prev) != 1) continue;
        //         res = (res + func(m - 1, i, prev)) % mod;
        //     }
        //     return dp[m][prev][prev_prev] = res % mod;
        // };

        //         int res = 0;
        // for (int i = 1; i <= 6; i++) {
        //     res = (res + func(n - 1, i, 0)) % mod;
        // }

        // return res % mod;

    }
};