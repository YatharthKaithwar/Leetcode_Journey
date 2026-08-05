class Solution {
public:
    int M = 1e9+7;
    int reverse(int num){// for reversing a number
        int ans=0;
        while( num>0){
            int remainder = num%10;
            ans = (ans*10)+remainder;
            num = num/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;

        for(int i=0;i<n;i++){// changing the nums value to nums[i]- reverse(nums[i])
            nums[i]=nums[i]-reverse(nums[i]);
        }
        int result = 0;
        for(int i = 0;i<n;i++){
            result = (result + map[nums[i]])%M;// adding ith value to the map and itss frequency to the result
            map[nums[i]]++;// incrasing the frequencty of the numbeer in the map
        }
        return result;
    }
};