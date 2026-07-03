class Solution {
public:
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