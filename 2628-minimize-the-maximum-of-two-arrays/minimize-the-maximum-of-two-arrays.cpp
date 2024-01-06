class Solution {
public:
    int gdc(int a, int b) {
        if (a % b == 0) return b;
        return gdc(b, a % b);
    }

    int lcm(int a, int b) {
        return min(long(INT_MAX), long(a) * b / gdc(a, b)); 
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int lcmResult = lcm(divisor1, divisor2);
        int start = 1, end = INT_MAX, res = -1;

        auto check_valid = [&] (int ans) -> bool {
            int both_invalid = ans / lcmResult;
            int arr1_invalid = ans / divisor1 - both_invalid;
            int arr2_invalid = ans / divisor2 - both_invalid;
            int both_valid = ans - both_invalid - arr1_invalid - arr2_invalid;

            if (uniqueCnt1 > arr2_invalid) both_valid -= uniqueCnt1 - arr2_invalid;
            if (uniqueCnt2 > arr1_invalid) both_valid -= uniqueCnt2 - arr1_invalid;

            return both_valid >= 0;
        };

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check_valid(mid)) {
                res = mid;
                end = mid - 1;
            } 
            else start = mid + 1;
        }

        return res;
    }
};