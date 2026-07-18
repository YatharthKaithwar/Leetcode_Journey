class Solution {
public:
    int findGCD(vector<int>& nums) {
//        int mini = *min_element(nums.begin(), nums.end());
//       int maxi = *max_element(nums.begin(), nums.end());
//
//        while (maxi != 0) {
//            int temp = maxi;
//            maxi = mini % maxi;
//            mini = temp;
//        }
//
//        return mini;

        int min_val = nums[0];
        int max_val = nums[0];
        
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        return gcd(min_val, max_val);
    }
};