vector<int> twoSum(vector<int>& nums, int target) {
    int difference;
    unordered_map<int,int> umap;

    //assigns each value to its respective index in the map
    for(int i = 0; i < nums.size(); i++) {
        umap[nums.at(i)] = i;
    }


    for(int i = 0; i < nums.size(); i++) {

        //finds one half of the sum
        difference = target - nums.at(i);
        
        //checks if the difference we calculated exists in the map
        //and if the differences is not the same as the index
        if(umap.count(difference) && umap[difference] != i) {
            return {i, umap[difference]};
        }
    }
    return {};
}