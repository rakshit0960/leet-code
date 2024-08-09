class Solution {
    typedef long long ll;
    bool check(vector<int>& nums, int k, int mid) {
        ll subarrayCount = 1;
        ll currSum = 0;

        for (int num : nums) {
            currSum += num;
            if (currSum > mid) {
                currSum = num;
                subarrayCount++;
            }
        }

        return subarrayCount <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        ll low = *max_element(nums.begin(), nums.end());
        ll high = accumulate(nums.begin(), nums.end(), 0ll);
        ll res = high;


        while (low <= high) {
        cout << low << " " << high << endl;
            ll mid = low + (high - low) / 2;
            if (check(nums, k, mid)) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return res;
    }
};