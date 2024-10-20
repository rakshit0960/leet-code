class Solution {
public:
    bool parseBoolExpr(string exp) {
        const int n  = exp.size();
        function<char(int, int)> func;

        func = [&] (int s, int e) {
          char op = exp[s];

          int t_count = 0, f_count = 0;
          for (int i = s + 2; i < e; i++) {
            if (exp[i] == 't') t_count++;
            else if (exp[i] == 'f') f_count++;
            else if (exp[i] == '&' || exp[i] == '|' || exp[i] == '!') {
                int b_cnt = 1;
                int j = i + 2;
                while (b_cnt) {
                    if (exp[j] == '(') b_cnt++;
                    if (exp[j] == ')') b_cnt--;
                    j++;
                }
                char ch = func(i, j - 1);
                cout << i << " " << j - 1 << " " << ch << endl;
                if (ch == 't') t_count++;
                else if (ch == 'f') f_count++;
                i = j - 1;
            }
          }

          if (op == '&') {
            if (f_count) return 'f';
            return 't';
          } else if (op == '|') {
            if (t_count) return 't';
            return 'f';
          } else if (op == '!') {
            if (t_count) return 'f';
            return 't';
          }

          throw 'wrong';
        };

        return func(0, n - 1) == 't';
    }
};