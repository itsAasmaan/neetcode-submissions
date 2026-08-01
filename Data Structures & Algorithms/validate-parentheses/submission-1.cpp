class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(const char &ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (!st.empty() && ((ch == ')' && st.top() == '(')
                    || (ch == '}' && st.top() == '{')
                    || (ch == ']' && st.top() == '['))) {
                    st.pop();

                    continue;
                }

                return false;
            }
        }

        return st.empty();
    }
};
