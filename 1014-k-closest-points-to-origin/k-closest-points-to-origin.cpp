class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int, int> queue_pair;
        priority_queue<queue_pair, vector<queue_pair>, greater<queue_pair>> pq;

        for (int i = 0; i < points.size(); i++) {
            int distence = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push({distence, i});
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            res.push_back(points[top.second]);
        }

        return res;
    }
};