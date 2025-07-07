int largestRectangleArea(vector<int>& heights) {
    int Max = 0;
    stack<pair<int, int>> st; //index, height

    //Figure out which heights can extend to the end of the graph.
    //For all the heights that do not extend to the end of the graph, 
    //we calculate the max area they can cover.
    for (int i = 0; i < heights.size(); i++) {
        int start = i;
        while (!st.empty() && st.top().second > heights[i]) {
            pair<int, int> top = st.top();
            int index = top.first;
            int height = top.second;
            Max = max(Max, height * (i - index));
            start = index;
            st.pop();
        }
        st.push({ start, heights[i] });
    }

    //Then, calculate the areas of all the heights that extend to the end
    while (!st.empty()) {
        int index = st.top().first;
        int height = st.top().second;
        Max = max(Max, height * (static_cast<int>(heights.size()) - index));
        st.pop();
    }
    return Max;
}