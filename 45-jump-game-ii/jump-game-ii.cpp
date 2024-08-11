class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        nums[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int jumps = nums[i];
            nums[i] = INT_MAX - 1000;

            for (int j = 1; j <= jumps && i + j < n; j++) {
                nums[i] = min(nums[i], 1 + nums[i + j]);
            }
        }

        return nums[0];
    }
};