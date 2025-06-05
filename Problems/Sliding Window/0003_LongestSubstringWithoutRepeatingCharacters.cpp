int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }

    unordered_set<char> Set;
    int Max = 0;
    int left = 0, right = 0;

    while(right < s.size()) {
        //if we have a repeting character, we need to
        //shrink the window from the left until it is gone
        while(Set.find(s[right]) != Set.end()) {
            Set.erase(s[left]);
            left++;
        }
        //add our current right value into the set
        Set.insert(s[right]);

        //if the range of values from right to left is
        //greater than our current max value, update the
        //value
        Max = max(Max, right - left + 1);

        //move on to the next value
        right++;
    }

    return Max;
}