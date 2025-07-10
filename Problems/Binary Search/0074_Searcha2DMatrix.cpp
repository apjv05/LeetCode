bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int last = matrix[0].size() - 1;
    int floor = 0, ceiling = matrix.size() - 1;

    while(floor <= ceiling) {
        int middle = (floor + ceiling) / 2;

        if(target >= matrix[middle][0] && target <= matrix[middle][last]) {
            int low = 0, high = matrix[middle].size() - 1;

            while(low <= high) {
                int mid = (high + low) / 2;

                if(matrix[middle][mid] == target) return true;
                else if(matrix[middle][mid] > target) high = mid - 1;
                else if(matrix[middle][mid] < target) low = mid + 1;
            }
            return false;
        }
        else if(matrix[middle][last] > target) ceiling = middle - 1;
        else if(matrix[middle][0] < target) floor = middle + 1;
    }
    return false;
}