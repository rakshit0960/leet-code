class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end()); 
        reverse(maximumHeight.begin(), maximumHeight.end()); 
        
        int curr = maximumHeight[0];
        long long res = maximumHeight[0];
        for (int i = 1; i < n; i++) {
            int h = maximumHeight[i];
            if (maximumHeight[i] >= curr) h = curr - 1;
            if (h <= 0) return -1;
            curr = h;
            res += h;
        }

        return res;
    }
};