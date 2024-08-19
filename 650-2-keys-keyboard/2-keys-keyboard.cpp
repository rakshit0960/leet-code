class Solution {
public:
    int minSteps(int n) {
        int count = 0, factor = 2;

        while (n > 1) {
            if (n % factor == 0) {
                count += factor;
                n = n / factor;
            }
            else factor++;
        }

        return count;
    }
};