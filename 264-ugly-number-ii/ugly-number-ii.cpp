class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> pq;


        pq.insert(1);
        for (int i = 1; i < n; i++) {
            int top = *pq.begin();
            pq.erase(top);

            pq.insert(top * 2ll);
            pq.insert(top * 3ll);
            pq.insert(top * 5ll);
        }

        return *pq.begin();
    }
};