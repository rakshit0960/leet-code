class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(256);
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            dp[ch] = max(1, dp[ch] + 1);
            for (int j = 1; j <= k; j++) {
                dp[ch] = max(dp[ch], dp[ch + j] + 1);
                dp[ch] = max(dp[ch], dp[ch - j] + 1);
            }
            res = max(res, dp[ch]);
        }

        return res;
    }
};