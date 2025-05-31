vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if(n < 4) return {};

    sort(nums.begin(), nums.end());
    vector<vector<int>> Result;
    
    //for loop to find the first number
    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        
        //for loop to find the second number
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            //while loop to find the last two numbers
            //uses 2 sum sorted array solution
            int a = j + 1, b = n - 1;
            while(a < b) {
                long long sum = (long long) nums[a] + nums[b] + nums[i] + nums[j];
                if(sum == target) {
                    Result.push_back({nums[i], nums[j], nums[a], nums[b]});
                    a++;
                    b--;
                    //prevents duplicates
                    while(a < b && nums[a] == nums[a - 1]) a++;
                    while(a < b && nums[b] == nums[b + 1]) b--;
                }
                else if(sum > target) b--;
                else a++;
            }
        }
    }
    return Result;
}