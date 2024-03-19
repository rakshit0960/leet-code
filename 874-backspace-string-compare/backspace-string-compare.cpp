class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '#') count += 1;
            else if (count) count--;
            else s1.push_back(s[i]);
        }

        count = 0;

        for (int i = t.size() - 1; i >= 0; i--) {
            if (t[i] == '#') count += 1;
            else if (count) count--;
            else s2.push_back(t[i]);
        }

        return s1 == s2;
    }
};