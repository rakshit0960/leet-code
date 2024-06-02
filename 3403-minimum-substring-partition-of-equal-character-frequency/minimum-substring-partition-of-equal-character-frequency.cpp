class Solution {
private:
    int f(int index, vector<int>& cache, string s) {
        int n = s.size();
        if (index >= n) return 0;
        if (cache[index] != -1) return cache[index];
        
        // if max(freq) * unique == n
        unordered_map<int, int> freq; // frequencies of characters
        
        int res = INT_MAX;
        int maxFreq = 0;
        for (int i = index; i < n; i++) {
            char ch = s[i]; // current char
            freq[ch]++; 
            int chFreq = freq[ch]; // frequency of current char 
            maxFreq = max(maxFreq, chFreq);

            if (maxFreq * freq.size() == i - index + 1)
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