bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    unordered_map<char, int> String1;
    unordered_map<char, int> String2;
    for(int i = 0; i < s.length(); i++) {
        String1[s[i]]++;
        String2[t[i]]++;
    }
    return String1 == String2;
}