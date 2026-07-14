class Solution {
public:
    bool rotateString(string s, string goal) {
        // Rotations cannot change the overall length of the string
        if (s.length() != goal.length()) {
            return false;
        }
        
        // s + s contains every single valid rotation of s
        std::string doubled = s + s;
        
        // Check if goal exists anywhere inside the doubled string
        return doubled.find(goal) != std::string::npos;
    }
};