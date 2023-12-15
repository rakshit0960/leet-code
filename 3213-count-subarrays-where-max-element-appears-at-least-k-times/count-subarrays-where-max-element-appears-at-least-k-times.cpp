class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int a = *max_element(nums.begin(), nums.end()), count = 0;
        
        long long res = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            count += (nums[r] == a);
            while (count >= k) {
                count -= (nums[l++] == a);
                res += nums.size() - r;
            }
            r++;
        }
        return res;
    }
};