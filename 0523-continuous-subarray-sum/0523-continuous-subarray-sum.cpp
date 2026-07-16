class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int n =nums.size();
//
//
//        for(int i = 0 ; i<n ; i++){
//            long long sum = 0;
//            for (int j =i;j<n;j++){
//                sum +=nums[j];
//                if(j-i+1>=2 && sum%k == 0){
//                    return true;
//                }
//            }
//        }
//        return false;


        unordered_map<int,int> mp;
        mp[0]=-1;
        long long prefixSum = 0;

        for(int i = 0;i<n;i++){
            prefixSum +=nums[i];
            int remainder = prefixSum % k;

            if(mp.count(remainder)){
                if(i-mp[remainder] >= 2){
                    return true;
                }
            }
            else{
                mp[remainder] = i; 
            }
        }
        return false;
    }
};