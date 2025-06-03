int trap(vector<int>& height) {
    if (height.empty()) {
        return 0;
    }
    
    int a = 0, b = height.size() - 1;
    int aMax = height[a], bMax = height[b];
    int total = 0;
    
    while(a < b) {
        //we increment and calculate how much water could be held
        //in our current index by assuming that we're always on
        //the bottleneck and the other max is > our current max
        if(aMax < bMax) {
            a++;
            aMax = max(aMax, height[a]);
            total += aMax - height[a];
        }
        else {
            b--;
            bMax = max(bMax, height[b]);
            total += bMax - height[b];
        }
    }
    return total;
}