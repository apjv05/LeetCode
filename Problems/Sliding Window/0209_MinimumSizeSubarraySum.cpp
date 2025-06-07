int minSubArrayLen(int target, vector<int>& nums) {
    if(nums.empty()) return 0;
    
    //min set to the max length that nums can be
    int CurSum = 0, Min = INT_MAX;
    int left = 0;

    for(int right = 0; right < nums.size(); right++) {
        //keep expanding until CurSum >= target
        CurSum += nums[right];

        //once CurSum >= Target keep contracting the window
        //until CurSum can be as small as it can
        while(CurSum >= target) {
            Min = min(Min, right - left + 1);
            CurSum -= nums[left];
            left++;
        }
    }
    if(Min == INT_MAX) return 0;
    return Min;
}