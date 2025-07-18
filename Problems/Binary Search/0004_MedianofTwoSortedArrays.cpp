double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& A = nums1;
    vector<int>& B = nums2;
    int total = A.size() + B.size();
    int half = (total + 1) / 2;

    //ensure we're working with the bigger array
    if (B.size() < A.size()) {
        swap(A, B);
    }

    int l = 0;
    int r = A.size();
    while (l <= r) {
        int i = (l + r) / 2;
        int j = half - i;

        //finding left side && bounds checking
        int Aleft = i > 0 ? A[i - 1] : INT_MIN;
        int Aright = i < A.size() ? A[i] : INT_MAX;
        int Bleft = j > 0 ? B[j - 1] : INT_MIN;
        int Bright = j < B.size() ? B[j] : INT_MAX;
        
        //check if our calculation is correct
        if (Aleft <= Bright && Bleft <= Aright) {
            //if even
            if (total % 2 == 0) { 
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            //if odd
            return max(Aleft, Bleft);
        }
        //shrink the size of the left half
        else if (Aleft > Bright) {
            r = i - 1;
        }
        //increase the size of the left half
        else {
            l = i + 1;
        }
    }
    return -1;
}
//this is impossible to figure out