class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int n = nums.size();
        int r = n - 1;
        int l = 0;
        int i = 0;
        while (i <= r) {
            if (nums[i] == 0) swap(nums[l++], nums[i++]);
            else if (nums[i] == 2) swap(nums[r--], nums[i]);
            else i++;
        }
        
    }
};