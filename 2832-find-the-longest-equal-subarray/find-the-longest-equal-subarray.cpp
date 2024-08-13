class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
       unordered_map<int, vector<int>> mp;

       for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
       } 


        int res = 0;
       for (auto& it : mp) {
            int count = it.first;
            vector<int>& indexes = it.second;
            const int n = indexes.size();

            int l = 0;
            for (int r = 0; r < n; r++) {
                while ((indexes[r] - indexes[l] + 1) - (r - l + 1) > k) l++;
                res = max(res, (r - l + 1) );
            }
       }

       return res;
    }
};