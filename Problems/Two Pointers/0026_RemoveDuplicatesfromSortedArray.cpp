int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int a = 0, b = 0;

    while(b < n) {
        //sets our unique value to the position of a
        nums[a] = nums[b];

        //finds the next unique value
        while(b < n && nums[a] == nums[b]) {
            b++;
        }

        //increments to where the next unique value needs to go
        a++;
    }
    //returns a because there are only 'a' number of unique values
    return a;
}