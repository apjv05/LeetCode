void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n);

    //works because if i + k is < n, then the number goes where it needs to
    //but if i + k is greater than n, it then starts at 0 and goes from there
    for(int i = 0; i < n; i++) temp[(i + k) % n] = nums[i];

    //copies temp array into input array
    for(int i = 0; i < n; i++) nums[i] = temp[i];
}