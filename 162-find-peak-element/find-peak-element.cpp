class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1]) right = mid - 1;
            else if (mid < n - 1 && nums[mid] < nums[mid + 1]) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};