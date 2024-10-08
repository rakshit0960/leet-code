class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> mp;
        long long total = accumulate(skill.begin(), skill.end(), 0ll);

        int sum = total / (skill.size()/2);
        long long res = 0;

        for (int skl : skill) mp[skl]++;
        
        for (auto it : mp) {
            long long num = it.first;
            int count = it.second;
            
            if (mp[sum - num] != count) return -1;

            res += num * (sum - num) * count;
        }

        return res / 2;

    }
};