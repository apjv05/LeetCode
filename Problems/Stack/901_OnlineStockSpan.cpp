class StockSpanner {
public:
    stack<pair<int,int>> st; //price, span
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;

        //while there is still previous days && our current price is > all the previous prices
        while(!st.empty() && st.top().first <= price) {
            //increment our span and pop the stack to move on to the previous day
            span += st.top().second;
            st.pop();
        }

        //push the found day on to the stack and return the span for the output
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */