class Solution {
    unordered_map<string, bool> memo;
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        // if (n != s2.size()) return false;
        if (s1.size() == 1) return s1 == s2;
        if (s1 == s2) return true;
        string key = s1 + " " + s2;
        if (memo.count(key)) return memo[key];

        for (int i = 1; i < n; i++) {
            bool notSwaped = (
                isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i, n - i), s2.substr(i, n - i))
            );

            bool swaped = (
                isScramble(s1.substr(0, i), s2.substr(n - i, i)) && 
                isScramble(s1.substr(i, n - i), s2.substr(0, n-i))
            );

            if (notSwaped || swaped) return memo[key] = true;
        }

        return memo[key] = false;
    }
};