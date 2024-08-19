class Solution {
public:
    int minSteps(int n) {
        function<int(int, int)> dfs;
        if (n == 1) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, - 1));

        dfs = [&] (int count, int paste) {
            if (count == n) return 1;
            if (count > n) return int(1e9);
            if (dp[count][paste] != -1) return dp[count][paste];
            int doPaste = 1ll + dfs(count + paste, paste);
            int doCopyPaste = 2ll + dfs(count + count, count);

            return dp[count][paste] = min(doPaste, doCopyPaste);
        };

        return dfs(1, 1);
    }
};