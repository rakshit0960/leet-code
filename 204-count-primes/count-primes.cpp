class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> sieve(n + 1, false);
        for (int i = 2; i < n; i++) {
            if (sieve[i]) continue;
            count += 1;
            for (int j = i; j < n; j += i) sieve[j] = true;
        }

        return count;
    }
};