class Solution {
private:
    long long findCost(vector<int>& nums, vector<int>& cost,int target){
        long long totalCost = 0;
        for(int i =0;i<nums.size();i++){
            totalCost += 1LL *abs(nums[i] - target) * cost[i];
        }
        return totalCost;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int left = *min_element(nums.begin(), nums.end());//minimum element of nums
        int right = *max_element(nums.begin(), nums.end());// maximum element of nums
        long long ans = findCost(nums, cost, left);


        while(left<right){
            int mid = left + (right-left)/2;

            long long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid+1);

            ans = min(cost1,cost2);

            if(cost1<cost2){// if cost1 is smaller than cost2 we eleminate right values of mid
                right = mid;
            }
            else{// else eliminate left values of mid
                left = mid+1;
            }
        }
        return ans;
    }
};