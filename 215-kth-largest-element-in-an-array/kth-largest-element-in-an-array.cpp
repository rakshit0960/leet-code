class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxHeap;

        for (int i : nums) maxHeap.push(i);

        for (int i = 1; i < k; i++) maxHeap.pop();

        return maxHeap.top();
    }
};