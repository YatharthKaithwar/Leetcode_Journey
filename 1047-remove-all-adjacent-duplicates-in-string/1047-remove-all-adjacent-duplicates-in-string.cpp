class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(char ch : s){
            if(!result.empty() && result.back() == ch){// checks if the strings contain 'ch' already
                result.pop_back();// pop it out
            }
            else{
                result.push_back(ch);// push it to the string if not in the result already
            }
        }
        return result;
    }
};