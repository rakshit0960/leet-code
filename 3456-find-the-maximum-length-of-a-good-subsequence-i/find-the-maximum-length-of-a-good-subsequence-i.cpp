class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int n = nums.size();

        function<int(int,int)> dfs;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        dfs = [&] (int i, int m) {
            if (i == n - 1) return 1;
            if (dp[i][m] != -1) return dp[i][m];

            int res = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    res = max(res, 1 + dfs(j, m));
                }
                else {
                    if (m == 0) continue;
                    res = max(res, 1 + dfs(j, m - 1));
                }
            }
            return dp[i][m] = res;
        };

        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, k));
        }

        return res;
    }
};