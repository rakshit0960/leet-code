class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res; 
        for (auto& querie : queries) {
            priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
            int k = querie[0], trim = querie[1];
            for (int i = 0; i < nums.size(); i++) pq.push({nums[i].substr(nums[i].size() - trim), i});
            for (int i = 1; i < k; i++) pq.pop();
            res.push_back(pq.top().second);
        }   
        return res;
    }
};