class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> IndexedMap; // unordered map <int,int>
        for (int i=0;i<nums.size();i++){ // iteration
            if(IndexedMap.find(nums[i]) != IndexedMap.end() && i - IndexedMap[nums[i]]<=k){
                return true; // If element is already in map and their index difference is <= k
            }
            IndexedMap[nums[i]]=i; // else insert number and index in map
        }
        return false;
    }
};