int findDuplicate(vector<int>& nums) {
    for(int num : nums) {
        int index = abs(num) - 1; //converts num to an index
        if(nums[index] < 0) return abs(num); //checks for duplicate
        nums[index] *= -1; //marks element as seen
    }
    return -1;
}