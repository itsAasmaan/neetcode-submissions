class MinStack {
public:
    stack<pair<int, int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        int minTillNow = val;

        if (st.empty() == false) {
            minTillNow = min(val, st.top().second);
        }

        st.push({val, minTillNow});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
