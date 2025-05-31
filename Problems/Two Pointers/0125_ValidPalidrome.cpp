bool isPalindrome(string s) {
    int a = 0, b = s.length() - 1;
    
    for (char& c : s) {
    c = tolower(c);
    }
    
    while(a < b) {
        if(!isalnum(s[a]))  {
            a++;
            continue;
        }
        else if(!isalnum(s[b])) {
            b--;
            continue;
        }
        else if(s[a] != s[b]) return false;
        a++;
        b--;
    }
    return true;
}