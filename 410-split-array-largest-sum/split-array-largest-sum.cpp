class Solution {
    typedef long long ll;
public:
    int splitArray(vector<int>& nums, int k) {
        const int n = nums.size();
        function<ll(int, int)> f;
        vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));
        vector<ll> prefix_sum(n);

        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        f = [&] (int i, int m) {
            if (m == 1)
                return prefix_sum[n - 1] - prefix_sum[i] + nums[i];
            if (dp[i][m] != -1)
                return dp[i][m];

            ll res = INT_MAX, curr_sum = 0;
            for (int j = i; j <= n - m; j++) {
                curr_sum += nums[j];
                ll max_sum = max(curr_sum, f(j + 1, m - 1));
                res = min(res, max_sum);
                if (curr_sum > res) break;
            }

            return dp[i][m] = res;
        };

        return f(0, k);
    }
};