vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> st; //{temp, index}
    vector<int> output(temperatures.size(), 0);

    for(int i = 0; i < temperatures.size(); i++) {
        int t = temperatures[i];

        //looks for a temp that is larger than the one on the stack.

        //each day we push temp and index onto the stack.
        while(!st.empty() && t > st.top().first) {
            //when we find a warmer day we pop it from the stack
            //and calculate the distance from the current day to
            //the warmer day.
            auto pair = st.top();
            st.pop();
            output[pair.second] = i - pair.second;
        }
        //pushes the current day to the stack
        st.push({t, i});
    }
    return output;
}