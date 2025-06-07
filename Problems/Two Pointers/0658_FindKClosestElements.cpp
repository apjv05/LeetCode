vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - 1;

    //keeps our group of elements k elements long
    while(right - left >= k) {
        if (abs(x - arr[left]) <= abs(x - arr[right])) {
            right--;
        }
        else {
            left++;
        }
    }
    vector<int> res;
    for(int i = left; i <= right; i++) res.push_back(arr[i]);
    return res;
}