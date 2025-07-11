int minEatingSpeed(vector<int>& piles, int h) {
    int floor = 1, ceiling = *max_element(piles.begin(), piles.end());
    int output = ceiling;
    
    while(floor <= ceiling) {
        //pick number of bannans we want to eat per hour
        int mid = (floor + ceiling) / 2;

        //test to see how long it would take at the rate we chose
        long long TotalTime = 0;
        for(int p : piles) {
            TotalTime += ceil(static_cast<double>(p) / mid);
        }

        //binary search to pick next number
        if(TotalTime <= h) {
            //save what could be our min number
            output = mid;
            ceiling = mid - 1;
        }
        else floor = mid + 1;
    }
    return output;
}
//Finding Smallest Element problem