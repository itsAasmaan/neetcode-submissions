class Solution {
   public:
    int calculateOperation(int a, int b, const string& token) {
        int result = 0;
        if (token == "+") {
            result = a + b;
        } else if (token == "-") {
            result = a - b;
        } else if (token == "*") {
            result = a * b;
        } else if (token == "/") {
            result = a / b;
        }

        return result;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int result = calculateOperation(a, b, token);

                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
