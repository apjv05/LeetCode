int maxArea(vector<int>& heights) {
    int Max = 0, a = 0, b = heights.size() - 1;
    
    while(a < b) {
        int CurMax;
        if(heights[a] > heights[b]) {
            int dist = b - a;
            CurMax = dist * heights[b];
        }
        else {
            int dist = b - a;
            CurMax = dist * heights[a];
        }

        if(CurMax > Max) Max = CurMax;
        
        //we increment the smaller one because if a later height
        //is taller than we may be able to find a better solution
        if(heights[a] < heights[b]) a++;
        else b--;
    }
    return Max;
}