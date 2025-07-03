class StockSpanner {
public:
    stack<pair<int,int>> st; //price, span
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;

        //while there is still previous days && our current price is > all the previous prices
        while(!st.empty() && st.top().first <= price) {
            //add the span of the previous day and pop it so that way we know that any other 
            //days we have visted before are all less than it
            //than pop the previous number because we have a new greatest number
            span += st.top().second;
            st.pop();
        }

        //push the found day on to the stack so we can look at it later for future reference
        //and return the span for the output
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */