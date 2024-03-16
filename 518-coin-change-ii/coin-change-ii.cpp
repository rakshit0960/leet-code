class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        function<int(int, int)> dfs;

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        dfs = [&] (int i, int amt) {
            if (i == 0) return int(!bool((amt % coins[i])));
            if (dp[i][amt] != -1) return dp[i][amt];

            int res = dfs(i - 1, amt);
            if (amt >= coins[i]) 
                res += dfs(i, amt - coins[i]);

            return dp[i][amt] = res;
        };

        return dfs(n - 1, amount);
    }
};