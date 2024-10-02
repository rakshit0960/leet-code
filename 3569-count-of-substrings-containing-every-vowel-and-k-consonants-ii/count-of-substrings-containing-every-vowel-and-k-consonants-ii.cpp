class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    long long countOfSubstrings(string word, int k) {
        const int n = word.size();
        unordered_map<char, int> mp;

        vector<int> nxt_c(n + 1);
        nxt_c[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            if (!isVowel(word[i + 1]))
                nxt_c[i] = i + 1;
            else
                nxt_c[i] = nxt_c[i + 1];
        }
        
        int l = 0, count = 0;
        long long res = 0;
        for (int r = 0; r < n; r++) {
            if (isVowel(word[r])) mp[word[r]]++;
            else count++;

            while (count > k) {
                if (isVowel(word[l])) mp[word[l]]--;
                else count--;
                if (mp[word[l]] == 0) mp.erase(word[l]);
                l++;
            }

            while (count == k && mp.size() == 5) {
                if (isVowel(word[l])) mp[word[l]]--;
                else count--;
                if (mp[word[l]] == 0) mp.erase(word[l]);
                l++;
                res += (nxt_c[r] - r);
            }
        }
        return res;
    }
};