vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> Map;
    for(int i = 0; i < nums.size(); i++) Map[nums[i]]++;

    vector<int> Result;
    for(const auto& [Key, Val] : Map) {
        if(Val > nums.size() / 3) Result.push_back(Key);
    }
    return Result;
}