class Solution {
public:
    bool equalFrequency(string word) {
        map<char, int>mp;
        int n = word.size();
        for(int i= 0; i<n; i++){
            mp[word[i]]++;
        }
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(auto it: mp){
            mn = min(mn, it.second);
            mx = max(mx, it.second);
        }
        if(mp.size() == 1)
            return 1;
        if(mp.size()* mn+1 == word.size())
            return 1;
        if(mx* (mp.size()-1) +1 == word.size() && mn == 1)
            return 1;
        return 0;
        
    }
};