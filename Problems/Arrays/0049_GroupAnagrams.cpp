vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //each string points to a vector that will have all of the characters in it with
    //their frequencies in it
    unordered_map<string, vector<string>> res;

    //loops through each string in our given stings
    for(const auto& s : strs) {

        //creates a vector named count with 26 zeros in it
        vector<int> count(26,0);

        //counts the frequency of each letter in the string
        for(char c : s) {
            count[c - 'a']++;
        }

        //converts the letter 'a' into a string from the int
        string key = to_string(count[0]);
        for(int i = 1; i < 26; i++) {
            //converts int frequency into its string version
            //for the rest of the numbers and puts them all in a string
            //the ',' makes it easier to proccess
            key += ',' + to_string(count[i]);
        }

        //pushs our formatted vector into the map so each string has its characters
        //frequency counted
        res[key].push_back(s);
    }

    //formats our map to the return type
    vector<vector<string>> result;
    for(const auto& pair : res) {
        result.push_back(pair.second);
    }
    return result;
}