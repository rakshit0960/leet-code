class Solution {
    int countPairs(vector<int>& nums, int diff) {
        const int n = nums.size();
        int count = 0;  

        int l = 0;
        for (int r = 1; r < n; r++) {
            while (nums[r] - nums[l] > diff) l++;
            count += r - l;
        }

        return count;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n - 1] - nums[0];
        int res = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (countPairs(nums, mid) >= k) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 

        return res;
    }
};