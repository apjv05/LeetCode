class MinStack {
public:
    stack<long> st;
    stack<long> minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        long lVal = val;

        st.push(lVal);
        if(minstack.empty()) minstack.push(lVal);
        else minstack.push(min(lVal, minstack.top()));
    }
    
    void pop() {
        st.pop();
        minstack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
//this did not feel like a medium problem, more like an easy