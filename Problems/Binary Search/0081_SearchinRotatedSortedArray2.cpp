bool search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while(low <= high) {
        int mid = (high + low) / 2;

        if(nums[mid] == target) return true;

        if(nums[low] < nums[mid]) { //left half
            if(nums[low] <= target && target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else if(nums[low] > nums[mid]) { //right half
            if(nums[mid] < target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
        else low++; //duplicate handler
    }
    return false;
}