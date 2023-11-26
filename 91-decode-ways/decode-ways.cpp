class Solution {
public:
    int numDecodings(string s) {

        function<int(int i)> func;
        int n = s.size();
        vector<int> memo(n, -1);

        func = [&] (int i) {
            if (i >= n) return 1;
            if (s[i] == '0') return 0;
            if (i == n - 1) return 1;

            if (memo[i] != -1) return memo[i];

            int res = func(i + 1);
            if ( i < n - 1 && ((s[i] - '0') * 10 + s[i + 1] - '0') < 27)
                res += func(i + 2);

            return memo[i] = res;
        };

        return func(0);
    }
};