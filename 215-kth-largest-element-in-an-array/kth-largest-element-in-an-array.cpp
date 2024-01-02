class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxHeap(nums.begin(), nums.end());
        for (int i = 1; i < k; i++) maxHeap.pop();
        return maxHeap.top();
    }
};