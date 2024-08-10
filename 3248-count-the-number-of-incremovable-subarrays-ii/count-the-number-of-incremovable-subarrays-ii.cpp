class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        const int n = nums.size();
        int startSequenceCount = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) startSequenceCount++;
            else break;
        }

        if (startSequenceCount == n - 1) {
            return n * (n + 1ll) / 2ll;
        }

        int endSequenceCount = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) endSequenceCount--;
            else break;
        }

        int i = 0, j = endSequenceCount;
        long long res = 0;
        while(j < n && i <= startSequenceCount) {

            while (j < n && nums[i] >= nums[j]) {
                j++;
            }
            if (j >= n) break;

            res += n - j + 1; 

            i++;
        }

        int es = (n - endSequenceCount);

        res += (n - endSequenceCount) + 1;
        res += (startSequenceCount  + 1 - i); 
        return res;
    }
};