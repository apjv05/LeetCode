int arrangeCoins(int n) {
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if (n > 0) count++;
        else break;
        n -= i;
    }
    return count;
}