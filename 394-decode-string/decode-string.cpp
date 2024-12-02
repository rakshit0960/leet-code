class Solution {
    bool isdigit(char ch) { return ch >= '0' && ch <= '9'; }

    string dfs(string s, int l, int r) {
        string res = "";

        while (l <= r) {
            if (!isdigit(s[l])) {
                res += s[l++];
                continue;
            }

            int digit_end = l;
            while (s[digit_end] != '[') digit_end++;
            int times = stoi(s.substr(l, digit_end - l));
            int section_end = digit_end;
            int count = 1;
            while (count) {
                section_end++;
                if (s[section_end] == '[') count++;
                if (s[section_end] == ']') count--;
            }
            string decoded_section = dfs(s, digit_end + 1, section_end - 1);

            while (times--) res += decoded_section;
            l = section_end + 1;
        }

        return res;
    }
public:
    string decodeString(string s) {
        return dfs(s, 0, s.size() - 1);
    }
};