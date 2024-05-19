class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
    int fn(int i, int j, bool can_step_back, int k) {
            if (i < 0) return 0;
            if (i > k + 1) return 0;
            
            int res = (i == k);
            if (dp.count(i) && dp[i].count(j) && dp[i][j].count(can_step_back)) 
                return dp[i][j][can_step_back];

            if (can_step_back) res += fn(i - 1, j, false, k);
            res += fn(i + (1<<j), j + 1, true, k);

            return dp[i][j][can_step_back] = res;
    }
public:
    int waysToReachStair(int k) {
        return fn(1, 0, true, k);
    }
};