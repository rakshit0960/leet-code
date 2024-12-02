class Solution {
public:
    string decodeString(string s) {
        const int n = s.size();
        stack<string> stk;
        stk.push("");
        int i = 0;
        while (i < n) {
            if (s[i] == ']') {
                string str = stk.top();
                stk.pop();
                int times = stoi(stk.top());
                stk.pop();
                string decoded = "";
                while (times--) decoded += str;
                decoded = stk.top() + decoded;
                stk.pop();
                stk.push(decoded);
                i++;
                continue;
            }

            if (!isdigit(s[i])) {
                string top = stk.top();
                stk.pop();
                stk.push(top + s[i]);
                i++;
                continue;
            }
            
            int openIndex = i;
            while(s[openIndex] != '[') openIndex++;
            stk.push(s.substr(i, openIndex - i));
            stk.push("");
            i = openIndex + 1;
        }
        return stk.top();
    }
};