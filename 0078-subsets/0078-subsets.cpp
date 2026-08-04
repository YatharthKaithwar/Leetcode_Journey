class Solution {
public:
    vector<vector<int>> result;
    void Recursion(int i,vector<int>& nums,vector<int>& temp){
        if(i>=nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);// pushing the ith value
        Recursion(i+1,nums,temp);//solving i+1th element
        temp.pop_back();// skipping the ith elemenet 
        Recursion(i+1,nums,temp);// ssolving i+1th element

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        Recursion(0,nums,temp);
        return result;
    }
};