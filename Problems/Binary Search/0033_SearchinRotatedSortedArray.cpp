int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    //find our rotation point
    while(low < high) {
        int mid = (high + low) / 2;
        if(nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }

    //figure out which side has our target value
    int pivot = low;
    low = 0;
    high = nums.size() - 1;
    if(target >= nums[pivot] && target <= nums[high]) low = pivot;
    else high = pivot - 1;

    //run binary search on the side with our target value
    while(low <= high) {
        int mid = (high + low) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}