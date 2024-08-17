class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if (st.empty()) leftSmall[i] = -1;
            else leftSmall[i] = st.top();
            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if (st.empty()) rightSmall[i] = n;
            else rightSmall[i] = st.top();
            st.push(i);
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, (rightSmall[i] -  leftSmall[i] - 1) * heights[i]);
        }

        return res;
    }
};