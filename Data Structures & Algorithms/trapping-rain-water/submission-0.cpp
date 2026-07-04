class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>lb(n), rb(n);
        stack<int>st;

        st.push(height[0]);
        lb[0] = height[0];
        for (int i=1; i<n; i++) {
            while (!st.empty() && st.top() <= height[i]) {
                st.pop();
            }
            if (!st.empty()) {
                lb[i] = st.top();
            } else {
                lb[i] = 0;
                st.push(height[i]);
            }
        }

        st = {};
        st.push(height[n-1]);
        lb[n-1] = height[n-1];
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && st.top() <= height[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rb[i] = st.top();
            } else {
                rb[i] = 0;
                st.push(height[i]);
            }
        }

        int result = 0;
        for (int i=0; i<n; i++) {
            int hgt = min(lb[i], rb[i]);
            if (hgt) {
                result += hgt - height[i];
            }
        }

        return result;
    }
};
