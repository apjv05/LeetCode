int characterReplacement(string s, int k) {
    //load in each unique character into the set
    unordered_set<char> Set(s.begin(), s.end());

    int Longest = 0;

    //test each unique character in the string
    for(char c : Set) {
        int Changes = 0, left = 0;

        //expand our window until there are too many characters that we need to change
        for(int right = 0; right < s.size(); right++) {
            if(s[right] == c) Changes++;

            //contract our window until we can make less changes to the
            //substring to keep our repeating character
            while((right - left + 1) - Changes > k) {
                if(s[left] == c) Changes--;
                left++;
            }

            //finally take  the range of our window and see if it is bigger
            //than a previous window
            Longest = max(Longest, right - left + 1);
        }
    }
    return Longest;
}