class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size();
        long long sum = accumulate(rolls.begin(), rolls.end(), 0ll);
        long long reqSum = mean * (n + m) - sum;

        if (reqSum < n || reqSum > 6ll * n) return {};

        int amt = reqSum / n;
        int rem = reqSum % n;
        
        vector<int> res(n, amt);
        for (int i = 0; i < rem; i++) res[i]++;
        return res;
    }
};