int longestConsecutive(vector<int>& nums) {
    unordered_set<int> Set;
    for(int i : nums) {
        Set.insert(i); 
    }

    int Max = 0;
    for(int i : Set) {
        if (Set.find(i - 1) == Set.end()) {
            int Count = 1;
            while(Set.find(i + Count) != Set.end()) {
                Count++;
            }
            Max = max(Max, Count);
        }
    }
    return Max;
}