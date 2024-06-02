class Solution {
private:
    int f(int index, vector<int>& cache, string s) {
        int n = s.size();
        if (index >= n) return 0;
        if (cache[index] != -1) return cache[index];
        
        vector<int> freq(26, 0); // frequencies of characters
        
        int res = INT_MAX;
        int maxFreq = 0, uniqueCount = 0;
        for (int i = index; i < n; i++) {
            char ch = s[i]; // current char
            if (freq[ch - 'a'] == 0) uniqueCount++;
            freq[ch - 'a']++; 
            int chFreq = freq[ch - 'a']; // frequency of current char 
            maxFreq = max(maxFreq, chFreq);

            // if max(freq) * unique == n
            if (maxFreq * uniqueCount == i - index + 1)
                res = min(res, 1 + f(i + 1, cache, s));
        }
        return cache[index] = res;
    }
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        // unordered_map<int, int> cache;
        vector<int> cache(n, -1);
        return f(0, cache, s);
    }
};