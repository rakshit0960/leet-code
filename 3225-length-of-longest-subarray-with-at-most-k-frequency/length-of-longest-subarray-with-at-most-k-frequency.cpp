class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        int res = 0;
        int s = 0;
        for (int e = 0; e < nums.size(); e++) {
            freq_map[nums[e]]++;
            while (freq_map[nums[e]] > k && s <= e) {
                freq_map[nums[s]]--;
                s++;
            }
            res = max(res, e - s + 1);
        }

        return res;
    }
};