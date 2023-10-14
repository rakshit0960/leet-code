class Solution {
public:
    int hamming(const string& s1, const string& s2) {
        int count = 0;    
        int n = s1.size();
        
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                count++;
        }
        return count;
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> next(n, n);
        vector<int> count(n, 1);
        
        for (int i = n - 1; i >= 0; --i) {
            bool found = false;
            
            for (int j = i + 1; j < n; j++) {
                if (groups[i] == groups[j]) continue;
                if (words[i].size() != words[j].size()) continue;
                if (hamming(words[i], words[j]) != 1) continue;
                if (count[j] + 1 < count[i]) continue;
                
                
                count[i] = count[j] + 1;
                next[i] = j;
                found = true;
                
            }
        }
        
        
        int maxidx = 0;
        for (int i = 0; i < n; i++) {
            if (count[maxidx] < count[i]) {
                maxidx = i;
            }
        }
        
        
        vector<string> res;
        
        int i = maxidx;
        while (i < n) {
            res.push_back(words[i]);
            i = next[i];
        }
        
        return res;
    }
};