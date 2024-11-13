class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long res = 0;
        for (int i = 0; i < n; i++) {
            auto lw = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto up =  upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);

            res += up - lw;
        }

        return res;
    }
};