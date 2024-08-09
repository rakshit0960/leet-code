class Solution {
    typedef long long ll;
    ll sum(vector<int>& arr, int s, int e) {
        ll sum = 0;
        for (int i = s; i <= e; i++) 
            sum += arr[i];
        
        return sum;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        const int n = nums.size();
        function<ll(int, int)> f;
        vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));

        f = [&] (int i, int m) {
            if (m == 1)
                return sum(nums, i, n - 1);
            if (dp[i][m] != -1)
                return dp[i][m];

            ll res = INT_MAX, curr_sum = 0;
            for (int j = i; j <= n - m; j++) {
                curr_sum += nums[j];
                ll max_sum = max(curr_sum, f(j + 1, m - 1));
                res = min(res, max_sum);
            }

            return dp[i][m] = res;
        };

        return f(0, k);
    }
};