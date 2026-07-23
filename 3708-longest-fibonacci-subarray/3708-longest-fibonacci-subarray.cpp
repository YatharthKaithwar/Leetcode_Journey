class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return n;

        int current_streak = 2;
        int max_streak = 2;

        for(int i=2;i<n;i++){// iteration starts from index 2
            if(nums[i]==nums[i-1]+nums[i-2]){// check if ith term is sum of two previous terms(fibonacci)
                current_streak +=1;// update streak
                max_streak = max(max_streak,current_streak);
            }
            else{
                current_streak = 2;// reset streak
            }
        }
        return max_streak;
    }
};