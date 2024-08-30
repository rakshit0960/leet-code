class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = nums.size();
        int res = 0;
        int currZeroCount = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) currZeroCount += 1;
            while (currZeroCount > k) {
                if (nums[l] == 0) currZeroCount -= 1;
                l++; 
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};