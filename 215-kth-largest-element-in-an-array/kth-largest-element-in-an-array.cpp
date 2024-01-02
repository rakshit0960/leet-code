class Solution {
public:
    void heapify(vector<int>& nums, int i, int size) {
        int right = i * 2 + 1;
        int left = i * 2 + 2;

        int largest = i;

        if (right < size && nums[largest] < nums[right])
            largest = right;
        
        if (left < size && nums[largest] < nums[left])
            largest = left;

        swap(nums[largest], nums[i]);

        if (largest != i) heapify(nums, largest, size);
    }

    void buildHeap(vector<int>& nums, int size) {
        for (int i = (size - 2) / 2; i >= 0; i--)
            heapify(nums, i, size);
    }

    int pop(vector<int>& nums, int& size) {
        size--;
        if (size >= 0) 
            swap(nums[0], nums[size]);
        heapify(nums, 0, size);
        return nums[size];
    }

    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        buildHeap(nums, size);
        for (int i = 1; i < k; i++) pop(nums, size);
        return pop(nums, size);
    }
};