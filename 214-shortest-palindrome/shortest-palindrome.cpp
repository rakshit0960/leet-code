class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> lps(2*n + 1, 0);

        string rev = s;
        reverse(rev.begin(), rev.end()); 
        string str = s + "$" + rev;

        for (int i = 1; i < 2*n + 1; i++) {
            int j = lps[i - 1];
            while (j > 0 && str[i] != str[j]) j = lps[j - 1];
            if (str[i] == str[j]) j++;

            lps[i] = j;
        }

        rev = s.substr(lps[2*n]);
        reverse(rev.begin(), rev.end());

        return rev + s;

    }
};