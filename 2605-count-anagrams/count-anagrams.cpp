class Solution {
private:
    static const int m = 1e9 + 7;
    static const int N = 1e5 + 1;
    
    long long fact[N];
    long long inv_fact[N];

    long long pow(int b, int p) {
        if (p == 0) return 1;
        if (p == 1) return b % m;

        long long res = pow(b, p / 2);
        res = (res * res) % m;
        if (p % 2 == 1) res = (res * (b % m)) % m;
        return res;
    }

    void initlize() {
        fact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = (fact[i - 1] * i) % m;
            inv_fact[i] = pow(fact[i], m - 2);
        }
    }

    long long arrangements (int n, const unordered_map<char, int>& freq) {
        long long res = fact[n];
        for (auto it : freq) 
            res = (res * inv_fact[it.second]) % m;
        return res;
    }
public:
    int countAnagrams(string s) {
        initlize();
        int n = s.size();
        int l = 0, res = 1;
        unordered_map<char, int> freq;
        for (int r = 0; r <= n; r++) {
            if (r == n || s[r] == ' ') {
                res = (res * arrangements(r - l, freq)) % m;
                freq.clear();
                l = r + 1;
            }
            else freq[s[r]]++;
        }
        return res;
    }
};