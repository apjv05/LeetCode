vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res(nums.size() - k + 1);
    deque<int> q;
    int left = 0, right = 0;

    while (right < nums.size()) {
        //we need to keep the queue in decreasing order, so if a new
        //number is added that is bigger than our current min, get rid of it
        while(!q.empty() && nums[q.back()] < nums[right]) q.pop_back();

        //add the current element's index to the back of the queue
        q.push_back(right);

        //if left is outside of the window, get rid of it
        if(left > q.front()) q.pop_front();

        //once the queue is k big, keep the biggest number at the front
        //of the queue
        if(right + 1 >= k) {
            res[left] = nums[q.front()];
            left++;
        }
        right++;
    }
    return res;
}