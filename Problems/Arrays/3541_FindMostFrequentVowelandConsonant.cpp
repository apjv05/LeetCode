class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> Vowels;
        unordered_map<char, int> Consonants;

        for(int i : s) {
            if(IsVowel(i)) Vowels[i]++;
            else Consonants[i]++;
        }
        
        int maxVowelFreq = 0;
        for(auto const& [key, val] : Vowels) {
            if(val > maxVowelFreq) {
                maxVowelFreq = val;
            }
        };

        int maxConsonantsFreq = 0;
        for(auto const& [key, val] : Consonants) {
            if(val > maxConsonantsFreq) {
                maxConsonantsFreq = val;
            }
        }
        return maxVowelFreq + maxConsonantsFreq;
    };

private:
    bool IsVowel(char Current) {
        return (Current == 'a' || Current == 'e' || Current == 'i' || Current == 'o' || Current == 'u');
    };
};