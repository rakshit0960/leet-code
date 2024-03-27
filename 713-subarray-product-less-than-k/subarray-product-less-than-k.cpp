class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        deque<int> dq;
        int product = 1;
        int count = 0;
        for (int num : nums) {
            product *= num;
            dq.push_back(num);
            while (!dq.empty() && product >= k) {
                int front = dq.front();
                dq.pop_front();
                product /= front;
            }
            count += dq.size();
        }
        return count;
    }
};