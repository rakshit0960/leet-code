class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);

            if (dq.back() < max(i - k + 1, 0)) dq.pop_back();

            if (i + 1 >= k) res.push_back(nums[dq.back()]);
        }

        return res;
    }
};