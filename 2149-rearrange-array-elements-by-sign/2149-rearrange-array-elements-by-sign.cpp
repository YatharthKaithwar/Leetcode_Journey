class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());


        int posIndex = 0;
        int negIndex = 1;

        for (int i = 0 ; i<nums.size() ; i++){
            if(nums[i]>0){ // if num is +ve then store it at the even index
                ans[posIndex] = nums[i];
                posIndex +=2;
               }
            else{// if num is -ve store it at odd index
                ans[negIndex] = nums[i];
                negIndex +=2;
            }
        }
        return ans;
    }
};