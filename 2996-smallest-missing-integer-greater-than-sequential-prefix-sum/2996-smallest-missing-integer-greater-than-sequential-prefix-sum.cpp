class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(begin(nums),end(nums));
        int seq_sum = nums[0];// saving 0th index value
        for(int j = 1; j<n ; j++){
            if(nums[j]==nums[j-1]+1){// checking the constraints 
                seq_sum+=nums[j];// adding to the sum
            }
            else{
                break;
            }
        }
        while(st.count(seq_sum)){// finding the value of sum in the set
            seq_sum++;// if sum value is present in the set then increase it by 1
        }
        return seq_sum;
    }
};