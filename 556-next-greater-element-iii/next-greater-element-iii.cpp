class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> res;

        int prev_digit = 0;
        int swaped_idx = -1;
        
        while (n != 0) {
            int digit = n % 10;
            n = n / 10;
            if (swaped_idx == -1 && prev_digit > digit) {
                int idx = res.size() - 1; 
                for (int i = res.size() - 1; i >= 0; i--) {
                    if (res[i] > digit) idx = i;
                    else break;
                }

                res.push_back(digit);
                swap(res[idx], res[res.size() - 1]);
                swaped_idx = res.size() - 1;
                continue;
            }
            res.push_back(digit);
            prev_digit = digit;
        }

        if (swaped_idx == -1) return -1;

        sort(res.begin(), res.begin() + swaped_idx, [] (int a, int b) { return b < a; } );

        long long result = 0;
        for (int i = res.size() - 1; i >= 0; i--) {
            result = result * 10 + res[i];
        }

        reverse(res.begin(), res.end());
        for (int nm: res) cout << nm;
            if (result > INT_MAX) return -1;
        return result;
    }
};