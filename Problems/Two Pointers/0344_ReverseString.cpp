void reverseString(vector<char>& s) {
    int a = 0, b = s.size() - 1;
    while(a < b) {
        swap(s[a], s[b]);
        a++;
        b--;
    }
}