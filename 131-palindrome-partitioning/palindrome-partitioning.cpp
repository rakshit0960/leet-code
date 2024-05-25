class Solution {
    bool is_valid(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    void backtrack(int i, vector<vector<string>>& res, vector<string>& curr, string s) {
        if (i == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (is_valid(s, i, j)) {
                curr.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, res, curr, s);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(0, res, curr, s);
        return res;
    }
};