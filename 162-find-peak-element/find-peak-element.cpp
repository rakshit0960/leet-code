class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i]) return i;
        }
       return (nums[n - 2] > nums[n - 1]) ? 0 : n - 1; 
    }
};