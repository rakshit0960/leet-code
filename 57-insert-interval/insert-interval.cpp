class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int i = 0, j;

        for (; i <= intervals.size(); i++) {
            if (i == intervals.size()) res.push_back(newInterval);
            
            else if (intervals[i][0] >= newInterval[0]) {
                res.push_back(newInterval);
                j  = i;
                break;
            }

            else if (intervals[i][1] >= newInterval[0]) {
                res.push_back(intervals[i]);
                res[i][1] = max(intervals[i][1], newInterval[1]);
                j = i + 1;
                break;
            }

            else res.push_back(intervals[i]);
        }


        while (j < intervals.size()) {
            if (res[i][1] >= intervals[j][1]) j++;
            else if (res[i][1] >= intervals[j][0]) {
                res[i][1] = intervals[j][1];
                j++;
            }
            else {
                res.push_back(intervals[j]);
                i++;
                j++;
            }
        }

        return res;
    }
};