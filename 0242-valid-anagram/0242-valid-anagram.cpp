class Solution {
public:
    bool isAnagram(string s, string t) {
         if (s.length() != t.length()) {   // Early exit: different lengths cannot be anagrams
            return false;
        }
        int count[26] = {0};   // Count array for 26 lowercase letters
        for (int i = 0; i < s.length(); i++) {  // Increment for s, decrement for t
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) { // If all counts are zero, strings are anagrams
            if (count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};