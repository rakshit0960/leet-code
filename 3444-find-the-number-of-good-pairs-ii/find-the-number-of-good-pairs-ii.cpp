class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> nm1;

        int smallest = INT_MAX, biggest = INT_MIN;
        for (int num : nums1) {
            if (num % k) continue;
            nm1[num / k]++;
            smallest = min(smallest, num / k);
            biggest = max(biggest, num / k);
        }

        if (nm1.size() == 0) return 0;

        unordered_map<int, long long> seen;
        long long res = 0;
        for (int num : nums2) {
            if (seen.count(num)) {
                res += seen[num];
                continue;
            }
            int mul = smallest - smallest % num;

            long long count = 0;
            while (mul <= biggest) {
                if (nm1.count(mul)) count += nm1[mul];
                mul += num;
            } 

            seen[num] = count;
            res += count;
        }

        return res;
    }
};