class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCase = 0;
        for(char c:word){
            if(isupper(c)){
                upperCase++;
            }
        }
        return upperCase == word.length()|| upperCase == 0 || upperCase == 1 && isupper(word[0]);
    }
};