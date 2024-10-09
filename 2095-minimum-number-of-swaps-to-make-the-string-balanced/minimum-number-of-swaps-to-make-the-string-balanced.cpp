class Solution {
public:
    int minSwaps(string s) {
        int o_count = 0, c_count = 0;

        for (char ch : s) {
            if (ch == '[') o_count++;
            else {
                if (o_count) o_count--;
                else c_count++;
            }
        }

        return (c_count + 1) / 2;
    }
};