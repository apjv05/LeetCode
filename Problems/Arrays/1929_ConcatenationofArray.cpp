vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans;

    //How many times we want to append our array to ans
    for(int i = 0; i < 2; i++) {
        //loops through nums with the integer num and 
        //appends ans with each value of nums
        for(int num : nums) {
            ans.push_back(num);
        }
    }
    return ans;
}