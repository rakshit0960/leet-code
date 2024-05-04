class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> stk;

        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && s[i] == ')' && stk.top().first =='(')
                stk.pop();
            else 
                stk.push({s[i], i});
        }

        if (stk.empty()) return s.size();

        int minIdx = INT_MAX, maxIdx = INT_MIN, prev = -1, res = 0;
        while (!stk.empty()) {
            auto top = stk.top();
            if (prev == -1) prev = top.second;
            res = max(res, prev - top.second - 1);
            prev = top.second;
            maxIdx = max(maxIdx, prev);
            minIdx = min(minIdx, prev);
            stk.pop();
        }


        res = max(res, minIdx);
        res = max(res, int(s.size()) - maxIdx - 1);

        return res;
    }
};