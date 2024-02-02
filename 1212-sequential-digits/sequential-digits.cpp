class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums(9);
        for (int i = 0; i < 9; i++) nums[i] = i + 1;

        vector<int> res;
        for (int j = 9; j > 0; j--) {
            for (int i = 0; i < j; i++) {
                if (nums[i] > high) return res;
                if (nums[i] >= low) res.push_back(nums[i]);
                nums[i] = nums[i] * 10 + (nums[i] % 10) + 1;
            }
        }
        return res;
    }
};