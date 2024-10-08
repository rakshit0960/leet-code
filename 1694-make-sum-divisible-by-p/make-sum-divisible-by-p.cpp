class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long total = 0;
        for (int num : nums) total += num;
        int reqMod = total % p;

        if (reqMod == 0) return 0;

        long long prefix = 0;
        int res = n;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;
            int req = (prefix - reqMod + p) % p;
            
            if (mp.count(req)) {
                res = min(res, abs(i - mp[req]));
            }

            mp[prefix] = i;
        }

        return res >= n ? -1 : res;
    }
};