class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        // XOR  operator returns 0 when comparing two identical elements (A XOR A = 0)) and returns the element itself when compared with 0 (A XOR 0 = A)
        
        for (char c : s) {  // XOR all characters in string s
            result ^= c;
        }
        
        for (char c : t) {  // XOR all characters in string t
            result ^= c;
        }
        
        return result;
    }
};