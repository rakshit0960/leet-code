class Solution {
    bool sameFreq(vector<int>& f1, vector<int>& f2) {
        for (int i = 0; i < f1.size(); i++) {
            if (f1[i] != f2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        // s1 in s2
        if (n1 > n2) return false;

        vector<int> freq(256, 0);
        vector<int> s1Freq(256, 0);
        
        for (int i = 0; i < n1; i++) {
            s1Freq[s1[i]]++;
            freq[s2[i]]++;
        }

        for (int i = n1; i <= n2; i++) {
            if (sameFreq(freq, s1Freq)) return true;

            if (i < n2) {
                freq[s2[i]]++;
                freq[s2[i - n1]]--;
            }
        }

        return false;
    }
};