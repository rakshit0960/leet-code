class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for (char ch : word) freq[ch]++;

        int maxFreq = INT_MIN, minFreq = INT_MAX;
        for (auto i : freq) {
            maxFreq = max(maxFreq, i.second);
            minFreq = min(minFreq, i.second);
        }

        if (freq.size() == 1 || 
        freq.size() == word.size() 
        || (minFreq == 1 && maxFreq * (freq.size() - 1) == word.size() - 1)
        || maxFreq - minFreq == 1 && minFreq * (freq.size() - 1) == word.size() - maxFreq) return true;

        else return false;
    }
};