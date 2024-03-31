class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int start = 0, end = 0, minIdx = -1, maxIdx = -1;
        long long res = 0;
        for (; end < nums.size(); end++) {
            if (nums[end] > maxK || nums[end] < minK) start = end + 1; 
            if (nums[end] == minK) minIdx = end;
            if (nums[end] == maxK) maxIdx = end;
            if (start > minIdx || start > maxIdx) continue;
            res += (min(maxIdx, minIdx) - start + 1);
        } 
        return res;
    }
};