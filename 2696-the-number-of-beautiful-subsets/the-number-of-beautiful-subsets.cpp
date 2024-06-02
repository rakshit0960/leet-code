class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        function<int(int, unordered_map<int, int>&)> dfs;
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;

        unordered_map<int, int> memo;
        dfs = [&] (int key, unordered_map<int, int>& group) {
            if (!group.count(key)) return 1;
            if (memo.count(key)) return memo[key];
            int skip = dfs(key + k, group);
            int include = ((1 << group[key]) - 1) * dfs(key + 2*k, group);

            return memo[key] = skip + include;
        };

        vector<unordered_map<int, int>> groups;
        unordered_set<int> visited;

        for (int num : nums) {
            if (visited.count(num)) continue;

            unordered_map<int, int> group;

            while (count.count(num - k)) num -= k;

            while (count.count(num)) {
                group[num] = count[num];
                visited.insert(num);
                num += k;
            }    

            groups.push_back(group);
        }
        
        int res = 1;
        for (auto& group : groups) {
            int minKey = INT_MAX;
            for (auto [key, _] : group) minKey = min(minKey, key);
            res *= dfs(minKey, group);
        }

        return res - 1;
    }   
};