class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector <int> result(n);
        int l = 0;
        int r = n-1;
        int placement = n-1;

        while(l <= r){
            if(abs(nums[l])>abs(nums[r])){// if absolute of left value is greater than right
                result[placement] = nums[l]*nums[l];//store the square of the left in the last position of result
                l++;// increease left
            }
            else{// else the right value is greater than the left
                result[placement] = nums[r]*nums[r];// store the square of right value in last position
                r--;// decresase  right
            }
            placement--;// decrease the placement value after store square
        }   
        return result;
    }
};