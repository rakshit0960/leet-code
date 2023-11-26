class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        dp[n - 1] = (s[n - 1] == '0') ? 0 : 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }  
            dp[i] = dp[i + 1];

            if (((s[i] - '0') * 10 + s[i + 1] - '0') <= 26) 
                dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};