class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;

        priority_queue<int, vector<int>, greater<int>> min_pq(nums.begin(), nums.end());
        priority_queue<int> max_pq(nums.begin(), nums.end());

        vector<int> min4, max4;

        for (int i = 0; i < 4; i++) {
            min4.push_back(min_pq.top());
            min_pq.pop();
            
            max4.push_back(max_pq.top());
            max_pq.pop();
        }

        int minDiff = INT_MAX;
        for (int i = 0; i < 4; i++) {
            cout << endl;
            minDiff = min(minDiff, max4[i] - min4[3 - i]);
        }
        return minDiff;
    }
};