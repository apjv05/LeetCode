vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> Map;
    vector<vector<int>> freq(nums.size() + 1);

    //count the frequency of nums
    for(int i : nums) {
        Map[i] = 1 + Map[i];
    }

    //map each frequency from the map
    //to the index of our vector
    for(const auto& entry : Map) {
        freq[entry.second].push_back(entry.first);
    }

    vector<int> Result;
    //itterate through our parent vector from greatest to least
    for(int i = freq.size() - 1; i > 0; i--) {

        //loop through each child vector
        for(int n : freq[i]) {

            //add our greatest frequency to the result vector
            Result.push_back(n);

            //once our resulting vector has k values of
            //our greatest frequency number we can return
            //our vector
            if(Result.size() == k) {
                return Result;
            }
        }
    }
    return Result;
}