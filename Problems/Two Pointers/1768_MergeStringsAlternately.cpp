string mergeAlternately(string word1, string word2) {
    int a = 0, b = 0;
    string Result;
    while(a < word1.length() || b < word2.length()) {
        if(a < word1.length()) {
            Result.push_back(word1[a]);
            a++;
        }
        if(b < word2.length()) {
            Result.push_back(word2[b]);
            b++;
        }
    }
    return Result;
}