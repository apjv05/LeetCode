int maxProfit(vector<int>& prices) {
    int maxprofit = 0;
    int a = 0, b = 1;
    
    while(b < prices.size()) {
        //if today's price is less than tomorrow's price 
        if (prices[a] < prices[b]) {
            //calculate the potential profit
            int profit = prices[b] - prices[a];
            
            //if our current max is less than the new max
            //assign a new max profit
            maxprofit = max(maxprofit, profit);
        }
        
        //puts a = to the lowest prices we've found so far
        else a = b;
        
        //increment b to move on to the next day
        b++;
    }
    return maxprofit;
}