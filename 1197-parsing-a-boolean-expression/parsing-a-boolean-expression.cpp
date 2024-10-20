class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch != ')') {
                st.push(ch);
                continue;
            }

            int t_count = 0, f_count = 0;
            while (st.top() != '(') {
                if (st.top() == 't') t_count++;
                else if (st.top() == 'f') f_count++;
                st.pop();
            }
            st.pop();

            if (st.top() == '&') {
                st.pop();
                if (f_count) st.push('f');
                else st.push('t');
            }
            else if (st.top() == '|') {
                st.pop();
                if (t_count) st.push('t');
                else st.push('f');
            } else if (st.top() == '!') { // !
                st.pop();
                if (t_count) st.push('f');
                else st.push('t');
            }
        }
        cout << st.top();
        return st.top() == 't';
    }
};