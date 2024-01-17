class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            int j = 0, k= i;
            while (j < needle.size() && haystack[k] == needle[j]) {
                j++;
                k++;
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};