vector<int> twoSum(vector<int>& numbers, int target) {
    int a = 0, b = numbers.size() - 1;

    while(a < b) {
        int curSum = numbers[a] + numbers[b];

        if(numbers[a] + numbers[b] == target && a != b) {
            return {a + 1, b + 1};
        }
        else if(curSum > target) b--;
        else if(curSum < target) a++;
    }
    return {};
}