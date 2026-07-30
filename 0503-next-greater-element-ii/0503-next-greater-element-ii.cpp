class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i = 0;i<2*n;i++){
            int current_num = nums[i%n];

            while(!st.empty() && nums[st.top()]<current_num){
                ans[st.top()]=current_num;
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
        }
        return ans;
    }
};