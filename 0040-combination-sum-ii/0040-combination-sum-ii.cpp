class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result,vector<int>& curr,int index){
        if(target<0){//if target becomes negative we return
            return;
        }
        if(target==0){// if target becomes 0 it is the desired result
            result.push_back(curr);
            return;
        }
        for(int i = index ; i<candidates.size();i++){// starting from the given index
            if(i>index && candidates[i]==candidates[i-1]){// if the vallue is equal to the previous value
                continue;                                 // then skip
            }
            curr.push_back(candidates[i]);// pushing the value at ith index
            solve(candidates, target-candidates[i],result,curr,i+1);//solve i+1th element & subtract it from target
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(begin(candidates),end(candidates));
        solve(candidates,target,result,curr,0);
        return result;
    }
};