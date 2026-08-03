class StockSpanner {
public:
    stack<int>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stack<int>temp;

        int count = 0;
        while(!st.empty() && st.top() <= price) {
            temp.push(st.top());
            st.pop();
            count++;
        }

        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        st.push(price);
        count++;

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */