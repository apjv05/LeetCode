int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap(stones.begin(), stones.end());

    while(maxHeap.size() > 1) {
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();

        if(x < y) maxHeap.push(y - x);
        else if (x > y) maxHeap.push(x - y);
    }

    if(maxHeap.empty()) return 0;
    return maxHeap.top();
}