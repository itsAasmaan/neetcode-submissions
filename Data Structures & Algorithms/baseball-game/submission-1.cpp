class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;

        for(const string &str: operations) {
            if (str == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            } else if (str == "D") {
                if (!st.empty()) {
                    int top = st.top();
                    st.push(top * 2);
                }
            } else if (str == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(stoi(str));
            }
        }

        int result = 0;
        while(st.empty() == false) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};