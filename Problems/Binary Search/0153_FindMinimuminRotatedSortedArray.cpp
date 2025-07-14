int findMin(vector<int> &nums) {
    int floor = 0, ceiling = nums.size() - 1;
    int lowest = nums[0];
    

    while(floor <= ceiling) {
        //if our range of the sub array is sorted,
        //we have found the min
        if(nums[floor] < nums[ceiling]) {
            lowest = min(lowest, nums[floor]);
            break;
        }

        int mid = (ceiling + floor) / 2;
        lowest = min(lowest, nums[mid]);

        //figure out which side is sorted
        if(nums[mid] >= nums[floor]) floor = mid + 1;
        else ceiling = mid - 1;
    }
    return lowest;
}