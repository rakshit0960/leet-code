class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        function<pair<int, int>(int, int)> helper;

        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(2*n, {-1, -1}));

        helper = [&] (int i, int m) {
            if (i >= n) return pair<int, int>({0, 0});
            if (dp[i][m].first != -1) return dp[i][m];
            int sum = 0;
            pair<int, int> res = {0, 0};

            for (int j = 0; j < 2*m && i + j < n; j++) {
                sum += piles[i + j];

                auto x = helper(i + j + 1, max(m, j + 1));

                if (sum + x.second > res.first) {
                    res.first = sum + x.second;
                    res.second = x.first;
                } 
            }

            return dp[i][m] = res;
        };

        return helper(0, 1).first;
    }
};