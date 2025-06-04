bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window;
    int L = 0;

    for(int R = 0; R < nums.size(); R++) {
        //checks if our window is too big
        if(R - L > k) {
            window.erase(nums[L]);
            L++;
        }
        if(window.find(num[R]) != window.end()) {
            return true;
        }
        window.insert(nums[R]);
    }
    return false;
}