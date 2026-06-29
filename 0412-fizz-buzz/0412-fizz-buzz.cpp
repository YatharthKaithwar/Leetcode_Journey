class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for (int i = 1; i <= n; ++i) {
            // Check divisibility by both 3 and 5 first
            if (i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            } 
            // Check divisibility by 3
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            } 
            // Check divisibility by 5
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            } 
            // Otherwise, store the number as a string
            else {
                ans.push_back(std::to_string(i));
            }
        }
        
        return ans;
    }
};