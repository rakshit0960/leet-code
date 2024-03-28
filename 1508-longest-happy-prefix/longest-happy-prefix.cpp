class Solution {
public:
    string longestPrefix(string s) {
        int size = s.size();
        vector<int> lps(size);

        for (int i = 1; i < size; i++) {
            if (s[i] == s[lps[i - 1]]) 
                lps[i] = lps[i - 1] + 1;
            else  {
                if (lps[i - 1] == 0)
                    lps[i] = 0;
                else if (s[lps[lps[i - 1] - 1]] == s[i])
                    lps[i] = lps[lps[i - 1] - 1] + 1;
                else if (s[i] == s[0])
                    lps[i] = 1;
                else 
                    lps[i] = 0;    
            }
        }
        if (lps[size - 1] == -1) return "";
        else return s.substr(0, lps[size - 1]);
    }
};