class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st; // Hash Set Declaration
        for (int num : nums){ // Iteration
            if(st.find(num)!=st.end()){ // No. is already in Set thenn Return True
            return true;   
        }
        st.insert(num);   // Number not present so inserting it in the set
        }
        return false;
    }
};