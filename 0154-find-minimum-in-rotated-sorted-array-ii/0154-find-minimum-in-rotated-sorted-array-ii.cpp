class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        int resultIndex = 0;

        while(left<=right){

            while(left<right && nums[left]==nums[left+1])left++;
            while(right>left && nums[right]==nums[right-1])right--;

            int mid = left + (right - left)/2;

            if(nums[mid]<nums[resultIndex]) resultIndex = mid;

            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return nums[resultIndex];
    }
};