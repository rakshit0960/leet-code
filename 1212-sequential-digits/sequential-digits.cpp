class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums(9);
        for (int i = 0; i < 9; i++) nums[i] = i + 1;

        vector<int> res;
        while (!nums.empty()) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > high) return res;
                if (nums[i] >= low) res.push_back(nums[i]);
                if (nums[i] % 10 == 9) nums.pop_back();
                nums[i] = nums[i] * 10 + (nums[i] % 10) + 1;
            }
        }
        return res;
    }
};