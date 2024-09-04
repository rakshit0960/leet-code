class Solution {
public:
    int getLucky(string s, int k) {
        const int n = s.size();
        string num = "";
        for (int ch : s) {
            int diff = (ch - 'a' + 1);
            if (diff > 9) {
                num += ((diff / 10) + '0');
                num += ((diff % 10) + '0');
            } else {
                num += diff + '0';
            }
        }  

        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (char digit : num) sum += digit - '0';

            num = "";
            while (sum) {
                num += (sum % 10) + '0';
                sum /= 10;
            }
            reverse(num.begin(), num.end());
        }

        return stoi(num);
    }
};