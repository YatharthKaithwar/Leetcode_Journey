class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        int resultIndex = 0;

        while(left<=right){

            while(left<right && nums[left]==nums[left+1])left++;//for skipping duplicate values from left
            while(right>left && nums[right]==nums[right-1])right--;//for skipping duplicate values from right

            int mid = left + (right - left)/2;

            if(nums[mid]<nums[resultIndex]) resultIndex = mid;// if mid indexed number is smaller  

            if(nums[mid]>nums[right]){// if mid element is greater then right-most element, it is definatly rotated
                left=mid+1;// updated left pointer
            }
            else{// else number is on left side
                right = mid-1;// update right pointer
            }
        }
        return nums[resultIndex];
    }
};