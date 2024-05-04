class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (!stk.empty() && s[i] == ')' && s[stk.top()] =='(')
                stk.pop();
            else 
                stk.push(i);
        }

        if (stk.empty()) return s.size();

        int a = n, b = 0, res = 0;
        while (!stk.empty()) {
            b = stk.top(); stk.pop();
            res = max(res, a-b-1);
            a = b;
        }
        res = max(res, a);

        return res;
    }
};