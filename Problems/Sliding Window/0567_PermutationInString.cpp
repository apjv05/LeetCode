bool checkInclusion(string s1, string s2) {
    //vectors that count each letter
    vector<int> Chars1(26);
    vector<int> Chars2(26);

    //load each character in s1 to the vector and count
    //each occurrence of each letter in s1
    for(char c : s1) Chars1[c-'a']++;

    for(int i = 0; i < s2.size(); i++) {
        //counts each occurrence of each letter in s2
        Chars2[s2[i]-'a']++;

        //corrects overcount of s2
        if(i >= s1.size()) Chars2[s2[i - s1.size()] - 'a']--;

        if (Chars2 == Chars1) return true;
    }
    return false;
}