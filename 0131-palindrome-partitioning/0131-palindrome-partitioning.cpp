class Solution {
public:
    int n;
    bool isPalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l] != s[r])
            return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string &s, int index, vector<string> &curr, vector<vector<string>> &result){
        if(index==n){// if we are at the end then definetly add it to result
            result.push_back(curr);
            return;
        }
        for(int i = index; i<n;i++){// starting from initial index till n
            if(isPalindrome(s,index,i)){// if it is palindrome
                curr.push_back(s.substr(index, i-index+1));// push the string in the curr
                backtrack(s,i+1,curr,result);// again backtrack i+1th index 
                curr.pop_back();// pop back the character if  backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(s,0,curr,result);
        return result;
    }
};