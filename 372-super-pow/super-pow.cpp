class Solution {
private:
int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

public:
    int superPow(int a, vector<int>& b) {
        constexpr int m = 1337 ;
        int base = a;
        int res = 1;
        for (int i = b.size() - 1; i >= 0; i--) {
            res = (res *  binpow(base, b[i], m)) % m;
            base = binpow(base, 10, m);
        }
        return res;
    }
};