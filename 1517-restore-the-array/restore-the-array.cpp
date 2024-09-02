class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int n = s.size();
        int dp[n + 1];
        int mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            string curr = "";
            for (int j = i; j < n; j++) {
                curr += s[j];
                long long num = stoll(curr);
                if (curr[0] == '0') break;
                if (num > k) break;
                if (num >= 1 && num <= k) 
                    dp[i] = (dp[i] + dp[j + 1]) % mod;
            }
        }

        return dp[0] % mod;
    }
};