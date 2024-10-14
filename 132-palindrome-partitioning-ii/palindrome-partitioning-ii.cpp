class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        bool isPalendrome[n][n];
        memset(isPalendrome, false, sizeof(isPalendrome));

        for (int i = 0; i < n; i++) isPalendrome[i][i] = true;
        for (int i = 0; i < n - 1; i++) isPalendrome[i][i + 1] = s[i] == s[i + 1];

        for (int diff = 2; diff < n; diff++) {
            for (int st = 0; st < n - diff; st++) {
                int e = st + diff;
                if (s[st] == s[e]) isPalendrome[st][e] = isPalendrome[st + 1][e - 1];
                else isPalendrome[st][e] = false;
                // if (isPalendrome[st][e]) cout << s.substr(st, diff + 1) << endl;
            }
        }

        // dp[i]: min partitioning s[0...i];
        // dp[i] = min of all (1 + dp[k] if k < i and isPalendrome[k + 1][i])
        int dp[n];
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = INT_MAX;
            if (isPalendrome[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int k = i - 1; k >= 0; k--) {
                if (isPalendrome[k + 1][i]) 
                    dp[i] = min(dp[i], 1 + dp[k]);
            }
        }

        return dp[n - 1];
    }
};