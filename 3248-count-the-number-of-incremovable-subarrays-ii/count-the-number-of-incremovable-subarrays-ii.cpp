class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        const int n = nums.size();

        // find the largest increasing sequnce from begning 
        int startSequenceCount = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) startSequenceCount++;
            else break;
        }

        // if whole array is increasing sequence
        if (startSequenceCount == n - 1) {
            return n * (n + 1ll) / 2ll;
        }


        // find largest increasing sequence which ends at n - 1
        int endSequenceCount = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) endSequenceCount--;
            else break;
        }

        // i is pointer at the starting sequence
        // j is pointer at the ending sequence
        int i = 0, j = endSequenceCount;
        long long res = 0;

        while(j <= n && i <= startSequenceCount + 1) {
            // add all valid array formed after removing subrrays [i + 1,...,j-1], [i + 1,...,j]
            // [i + 1,...,j+1], ..., [i + 1,...,n-1] 
            // toal n - j + 1 valid arrays
            res += n - j + 1; 

            // find the index in end sequence which in greater than curret i index
            while (j < n && nums[i] >= nums[j]) {
                j++;
            }
            // if no number in end sequence is greater than current i index 
            if (j > n) break;


            // go to the next index in starting array
            i++;
        }
        return res;
    }
};