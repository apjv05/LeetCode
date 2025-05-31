bool validPalindrome(string s) {
    int a = 0, b = s.length() - 1;

    while(a < b) {
        //if our two characters are not equal, it then skips  those letters
        //and checks if the rest of the string besdies the unequal chars
        //are a palidrome and returns true based on the isPalidrome func
        if(s[a] != s[b]) return isPalidrome(s, a + 1, b) || isPalidrome(s, a, b - 1);
        a++;
        b--;
    }
    return true;
}

bool isPalidrome(const string& s, int a, int b) {
    while(a < b) {
        if(s[a] != s[b]) return false;
        a++;
        b--;
    }
    return true;
}