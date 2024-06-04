class Solution {
public:
    int longestPalindrome(string s) {
        bool charSet[256];
        fill(charSet, charSet + 256, false);
        
        int res = 0, oddCount = 0;
        for (char ch : s) {
            if (charSet[ch]) {
                charSet[ch] = false;
                oddCount--;
                res += 2;
            } else {
                charSet[ch] = true;
                oddCount++;
            }
        }

        return res + bool(oddCount);
    }
};