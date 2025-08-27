vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, pair<int, int>>> maxHeap; // dist, (x,y)

    for(auto& point : points) {
        int dist = pow(point[0], 2) + pow(point[1], 2);
        maxHeap.push({dist, {point[0], point[1]}});

        if(maxHeap.size() > k) maxHeap.pop();
    }

    vector<vector<int>> output;
    while(!maxHeap.empty()) {
        output.push_back({maxHeap.top().second.first,
                            maxHeap.top().second.second});
        maxHeap.pop();
    }
    return output;
}