class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();

        vector<vector<int>> dp(c, vector<int>(c, 0));
        for (int diff = 2; diff < c; diff++) {
            for (int l = 0; l < c - diff; l++) {
                int r = l + diff;
                // cout << l << " " << r << endl;
                int ans = INT_MAX;
                for (int i = l + 1; i < r; i++) {
                    ans = min(ans, cuts[r] - cuts[l] + dp[l][i] + dp[i][r]);
                }
                dp[l][r] = ans;
            }
        }

        return dp[0][c - 1];
    }
};