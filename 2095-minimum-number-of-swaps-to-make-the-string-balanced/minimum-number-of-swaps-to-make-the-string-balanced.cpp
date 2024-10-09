class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for (char ch : s) {
            if (!st.empty() && st.top() == '[' && ch == ']') st.pop();
            else st.push(ch);
        }


        return (st.size() / 2 + 1) / 2;
    }
};