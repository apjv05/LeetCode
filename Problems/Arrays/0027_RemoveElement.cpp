int removeElement(vector<int>& nums, int val) {
    int Count = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == val) Count++;
    }
    for(int i = 0; i < Count; i++) nums.erase(find(nums.begin(), nums.end(), val));
    return nums.size();
}