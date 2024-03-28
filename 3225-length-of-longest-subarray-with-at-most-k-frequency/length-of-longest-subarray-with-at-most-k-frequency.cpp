class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        deque<int> dq;
        int res = 0;

        for (int num : nums) {
            freq_map[num]++;
            dq.push_back(num);
            while (freq_map[num] > k) {
                int front = dq.front();
                dq.pop_front();
                freq_map[front]--;
            }
            res = max(res, (int)dq.size());
        }

        return res;
    }
};