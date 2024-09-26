class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        const int n = arr1.size();
        unordered_set<int> pfx;


        for (int num : arr1) {
            while (num) {
                pfx.insert(num);
                num /= 10;
            }
        }

        int res = 0;
        
        for (int num : arr2) {
            int len = log10(num) + 1;
            while (num) {
                if (pfx.count(num)) break;
                num /= 10;
                len--;
            }
            res = max(res, len);
        }
        
        return res;
    }
};