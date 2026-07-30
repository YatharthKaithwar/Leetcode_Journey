class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i = 0;i<2*n;i++){// iterating twice for circular 
            int current_num = nums[i%n];

            while(!st.empty() && nums[st.top()]<current_num){//Resolving greater element in the stack
                ans[st.top()]=current_num;// storing top element greater
                st.pop();
            }
            if(i<n){ // Only push indices from the first pass to avoid redundancy
                st.push(i);
            }
        }
        return ans;
    }
};