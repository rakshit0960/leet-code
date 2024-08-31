class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);
        int l = 0, res = 0;
        for (int r = 0; r < n; r++) {
            count[s[r] - 'A']++;
            while (r - l + 1 - *max_element(count.begin(), count.end()) >k) {
                count[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};