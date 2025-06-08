string minWindow(string s, string t) {
    if (t.empty()) return "";

    unordered_map<char, int> tCount, Window;
    for(char c : t) tCount[c]++;

    //have is that we need that are in our window
    //need is how many chars we need from string t
    int have = 0, need = tCount.size();

    //used to hold the min indexes
    pair<int, int> res = {-1, -1};

    //used to hold the min length
    int ResLength = INT_MAX;
    int Left = 0;

    for(int Right = 0; Right < s.length(); Right++) {
        //used to check the char of our right val
        char c = s[Right];
        Window[c]++;

        //if our current char exists in string t and
        //the frequency of char c is =, increment have
        if(tCount.count(c) && Window[c] == tCount[c]) have++;


        while(have == need) {
            //check if we have a solution
            if((Right - Left + 1) < ResLength) {
                ResLength = Right - Left + 1;
                res = {Left, Right};
            }

            //move a char outside of the window and update our Map accordingly
            Window[s[Left]]--;
            if(tCount.count(s[Left]) && Window[s[Left]] < tCount[s[Left]]) have--;
            Left++;
        }
    }
    
    if(ResLength == INT_MAX) return "";
    return s.substr(res.first, ResLength);
}