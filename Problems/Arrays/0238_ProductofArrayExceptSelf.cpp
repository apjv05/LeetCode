vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> Prefix(n), Suffix(n), Output(n);

    Prefix[0] = 1;
    for(int i = 1; i < nums.size(); i++) {
        Prefix[i] = Prefix[i - 1] * nums[i - 1];
    }

    Suffix[n - 1] = 1;
    for(int i = nums.size() - 2; i >= 0; i--) {
        Suffix[i] = Suffix[i + 1] * nums[i +1];
    }

    for(int i = 0; i < nums.size(); i++) {
        Output[i] = Prefix[i] * Suffix[i];
    }
    return Output;
}