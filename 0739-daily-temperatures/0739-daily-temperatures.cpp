class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack <int> st;

        for(int i = 0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int prevIndex = st.top();
                st.pop();
                res[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return res;
    }
};