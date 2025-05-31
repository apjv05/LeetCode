vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for(int i = 0; i < nums.size(); i++) {
        //checks if we already used this first number
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        //use sorted two sum solution to find the rest of the numbers
        int a = i + 1, b = nums.size() - 1;
        while(a < b) {
            int curSum = nums[i] + nums[a] + nums[b];
            if(curSum > 0) b--;
            else if(curSum < 0) a++;
            else {
                result.push_back({nums[i], nums[a], nums[b]});
                a++;
                b--;
                while(a < b && nums[a] == nums[a - 1]) a++;
            }
        }
    }
    return result;
}