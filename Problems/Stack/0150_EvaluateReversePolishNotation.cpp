int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(const string& c : tokens) {
        if(c == "+") {
            int Num2 = st.top();
            st.pop();
            int Num1 = st.top();
            st.pop();

            st.push(Num1 + Num2);
        }
        else if(c == "-") {
            int Num2 = st.top();
            st.pop();
            int Num1 = st.top();
            st.pop();

            st.push(Num1 - Num2);
        }
        else if(c == "*") {
            int Num2 = st.top();
            st.pop();
            int Num1 = st.top();
            st.pop();

            st.push(Num1 * Num2);
        }
        else if(c == "/") {
            int Num2 = st.top();
            st.pop();
            int Num1 = st.top();
            st.pop();

            st.push(Num1 / Num2);
        }
        else st.push(stoi(c));
    }
    return st.top();
}
//this was pretty easy
//as soon as you identify that you need a stack
//it takes no longer than 10 mins to solve