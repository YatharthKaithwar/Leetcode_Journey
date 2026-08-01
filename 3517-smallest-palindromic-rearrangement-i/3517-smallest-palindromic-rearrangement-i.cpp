class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        int mid = n/2;
        sort(begin(s),begin(s)+mid); // sort first half

        for(int i = 0; i<mid;i++){// iterate first half to store th values on right half
            s[n-1-i]=s[i];
        }
        return s;
    }
};