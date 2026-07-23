class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid] == target) return true;
            //Cannot determine which half is sorted due to duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++ , high--;
                continue;
            }

        else if (nums[low] <= nums[mid]){//Left half is guaranteed to be sorted
            if (nums[low] <= target && target < nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{//Right half is guaranteed to be sorted
            if (nums[mid] < target && target <= nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }    
        }
        return false;
    }
};