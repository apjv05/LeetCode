int shipWithinDays(vector<int>& weights, int days) {
    int floor = *max_element(weights.begin(), weights.end());
    int ceiling = accumulate(weights.begin(), weights.end(), 0);
    int LeastWeight = 0;

    while(floor <= ceiling) {
        int mid = (floor + ceiling) / 2;

        int DaysNeeded = 1;
        int CurWeight = 0;
        for(int w : weights) {
            if(CurWeight + w > mid) {
                DaysNeeded++;
                CurWeight = 0;
            }
            CurWeight += w;
        }

        if(DaysNeeded > days) {
            floor = mid + 1;
        }
        else {
            LeastWeight = mid;
            ceiling = mid - 1;
        }
    }
    return LeastWeight;
}