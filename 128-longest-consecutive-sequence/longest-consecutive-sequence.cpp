class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet;

        for (int num : nums) numsSet.insert(num);

        int res = 0;

        for (int num : numsSet) {
            if (numsSet.count(num - 1)) continue;
            int count = 0, curr = num; 
            while (numsSet.count(curr)) {
                count++;
                curr = curr + 1;
            }
            res = max(res, count);
        } 

        return res;
    }
};