class Solution {
public:
//  bool uniqueOccurrences(vector<int>& arr) {
//       vector<int> vec(2001,0);
//       for (int &x : arr){
//           vec[x+1000]++;  
//               }
//        sort (begin(vec),end(vec));
//
//        for (int i = 1; i<2001; i++){
//         if(vec[i]!=0 vec[i]==vec[i-1])
//         return false;
//         }
//         return false;
//       }
//};
//
//
//

    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int num : arr){
            mp[num]++;
        }

        unordered_set<int> unique_freq;

        for(auto &iteration : mp){
            int freq = iteration.second; //it.first= number

            if(unique_freq.find(freq)!=unique_freq.end())
            return false;
            unique_freq.insert(freq);       
            
             }
             return true;
    }
};