string longestCommonPrefix(vector<string>& strs) {
    //loops through the length of the first string in the vector
    //since the first string could be the longest one we need to provide
    //logic later that will stop the for loop sooner
    for(int i = 0; i < strs[0].length(); i++) {

        //loop through each string in the vector
        for(const string& s : strs) {
            //we are essentally comparing the other strings to the first one with
            //this for loop

            //if i is the full length of the string, return the whole first string
            //if our current string's i letter is not the same as the first string's i letter
            //return our current string's prefix up to i
            if(i == s.length() || s[i] != strs[0][i]) {
                return s.substr(0, i); 
            }
        }
    }
    return strs[0];
}