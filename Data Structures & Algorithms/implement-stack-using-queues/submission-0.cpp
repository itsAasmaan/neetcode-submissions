class MyStack {
public:
    queue<int>st;
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int>temp;
        while(st.empty() == false) {
            temp.push(st.front());
            st.pop();
        }

        st.push(x);
        while(temp.empty() == false) {
            st.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() {
        if (!st.empty()) {
            int x = st.front();
            st.pop();

            return x;
        }

        return -1;
    }
    
    int top() {
        if (!st.empty()) {
            return st.front();
        }

        return -1;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */