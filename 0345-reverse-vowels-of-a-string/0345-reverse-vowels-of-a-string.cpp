class Solution {
public:
    bool isVowel(char c){// fumction foor checking vowe;s in strings
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            while(l<r && !isVowel(s[l])){// if string has vowel from left side
                l++;
            }
            while(l<r && !isVowel(s[r])){// if string has vowel from right side
                r--;
            }
            if(l<r){
                swap(s[l],s[r]);// swap the vowels
                l++;// increase left
                r--;// decrease right
            }
        }
        return s;
    }
};