class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;

        int res = 1;
        int count = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) { 
            if (nums[i] == prev) continue;
            if (nums[i] == prev + 1) count++;
            else count = 1;
            prev = nums[i]; 
            res = max(res, count);
        }

        return res;
    }
};