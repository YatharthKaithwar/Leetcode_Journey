class Solution {
public:
    int maxProduct(vector<int>& nums) {
 //       int ans = nums[0];
//      for (int i =0;i<nums.size();i++){
//         int product = 1;
//         for(int j = i;j<nums.size();j++){
//             product *= nums[j];
//             ans = max(ans,product);            
//            }
//        }
//        return ans;
      int prefix = 1;
      int suffix = 1;
      int ans = INT_MIN;
      int n = nums.size();
      for (int i=0 ; i<n ; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix = prefix*nums[i];
        suffix = suffix*nums[n-i-1];
        ans = max(ans,max(prefix,suffix));
      }
      return ans;
      
   }
};