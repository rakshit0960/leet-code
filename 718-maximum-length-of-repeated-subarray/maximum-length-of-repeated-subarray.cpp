class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1));


        // dp[i][j] = 1 + dp[i + 1][j + 1] if n1[i] == n2[j]
        int res = 0;
        for (int i = s1 - 1; i >= 0; i--) {
            for (int j = s2 - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};