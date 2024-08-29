class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<long long > prefix(n + 1, 0);
        prefix[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int l = 0, res = 0;
        for (int r = 0; r < n; r++) {
            while ((r - l + 1ll) * nums[r] - (prefix[r + 1] - prefix[l]) > k) {
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};