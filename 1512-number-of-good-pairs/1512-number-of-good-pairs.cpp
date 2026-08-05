class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> map;
        int result = 0;;

        for(int &num : nums){
            result += map[num];// pushing the value in map
            map[num]++;// increasing the frequency of the value in the map
        }
        return result;
    }
};