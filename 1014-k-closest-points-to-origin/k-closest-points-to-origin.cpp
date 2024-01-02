class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int, vector<int>> queue_pair;
        priority_queue<queue_pair, vector<queue_pair>, greater<queue_pair>> pq;

        for (auto point : points) {
            int x = point[0], y = point[1];
            int distence = pow(x, 2) + pow(y, 2);
            pq.push({distence, point});
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);
        }

        return res;
    }
};