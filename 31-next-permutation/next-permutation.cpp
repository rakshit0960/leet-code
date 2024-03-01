class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = nums.size() - 2;
        for ( ; pivot >= 0; pivot--) {
            if (nums[pivot] < nums[pivot + 1]) break;
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }


        int swp = pivot + 1;

        while (swp < nums.size() && nums[swp] > nums[pivot]) swp++;

        swap(nums[pivot], nums[swp - 1]);

        reverse(nums.begin() + pivot + 1, nums.end());
        

    }
};