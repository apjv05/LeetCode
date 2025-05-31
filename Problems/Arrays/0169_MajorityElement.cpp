int majorityElement(vector<int>& nums) {
    unordered_map<int, int> Map;

    for(int i = 0; i < nums.size(); i++) {
        Map[nums[i]]++;
    }

    int Max = 0, Majority;
    for(const auto& [Key, Val] : Map) {
        if(Val > Max) {
            Max = Val;
            Majority = Key;
        }
    }
    return Majority;
}