class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        int dp[n + 1], freq[26];
        fill(dp, dp + n + 1, INT_MAX);
        dp[n] = 0;
        for (int i : dp) cout << i << " ";

        for (int i = n - 1; i >= 0; i--) {
            fill(freq, freq + 26, 0);
            int uniqueChar = 0, maxFreq = 0;
            for (int j = i; j < n; j++) {
                char ch = s[j];
                if (freq[ch - 'a'] == 0) uniqueChar++;
                freq[ch - 'a']++;
                maxFreq = max(maxFreq, freq[ch - 'a']);

                if (maxFreq * uniqueChar == j - i + 1)
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }


        return dp[0];
    }
};