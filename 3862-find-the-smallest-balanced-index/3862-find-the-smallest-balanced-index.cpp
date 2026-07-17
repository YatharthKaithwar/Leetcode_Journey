class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
           long long sum = 0;
        long long product = 1;

        for (int x : nums)
            sum += x;

        for (int i = nums.size() - 1; i >= 0; i--) {

            sum -= nums[i];

            if (sum == product)
                return i;

             if (product > LLONG_MAX / nums[i])
                product = LLONG_MAX;
            else
                product *= nums[i];


            if (product >= sum)
                break;
        }

        return -1;
    }
};