class Solution {
public:
    bool checkIfPangram(string sentence) {
        //vector<int> arr(26,0);

        //for(char &ch : sentence){
        //    int index = ch - 'a';// subtacting everi char,s aski value to a,s aski value
        //    arr[index]++;
        //}
        //for(int &count : arr){// 
        //    if(count == 0){// if any index has zero value than an alphabet is definetly absent
        //        return false;
        //    }
        //}
        //return true;
        unordered_set<char> s;// only stores unique element once
        for(char c: sentence){
            s.insert(c);// inserting elements in set
        }
        if(s.size() == 26){// if stack is of size 36 then all alphabets are present
            return true;
        }
        else{// else not present
            return false;
            }
    }
};