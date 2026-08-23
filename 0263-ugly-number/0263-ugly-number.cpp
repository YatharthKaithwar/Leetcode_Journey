class Solution {
public:
    bool isUgly(int n) {
           // Edge case: Ugly numbers must be positive integers
        if (n <= 0) return false;
        
        // Divide by the allowed prime factors as much as possible
        for (int factor : {2, 3, 5}) {
            while (n % factor == 0) {
                n /= factor;
            }
        }
        
        // If n is reduced to 1, it means it only had 2, 3, or 5 as prime factors
        return n == 1;
    }
};