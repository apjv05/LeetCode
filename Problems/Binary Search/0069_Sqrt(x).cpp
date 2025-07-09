int mySqrt(int x) {
    if(x == 0 || x == 1) return x;

    int low = 0, high = x;
    int res = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if((long long) mid * mid > x) high = mid - 1;
        else if((long long) mid * mid < x) {
            low = mid + 1;
            res = mid;
        }
        else return mid;
    }
    return res;
}