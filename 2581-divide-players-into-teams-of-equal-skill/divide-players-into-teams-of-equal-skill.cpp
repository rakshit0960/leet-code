class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int n = skill.size();
        sort(skill.begin(), skill.end());

        int i = 0, j = n - 1;

        int sum = skill[0] + skill[n - 1];
        long long res = 0;
        while (i < j) {
            if (skill[i] + skill[j] != sum) return - 1;
            res += skill[i] * skill[j];
            i++;
            j--;
        }

        return res;
    }
};