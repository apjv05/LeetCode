bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> UsedNums;

    for(int i : nums) {
        if(UsedNums.count(i) == 1) return true;
        UsedNums.insert(i);
    }
    return false;
}