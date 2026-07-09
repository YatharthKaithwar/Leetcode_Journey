class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,0); 
        for(int i=0;i<n;i++){
            if(colors[i]!=0)continue;

            queue<int> q;
            q.push(i);
            colors[i]=1;
        

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                if(colors[it]==0){
                    colors[it]= -colors[node];
                    q.push(it);
                }

                else if(colors[it]==colors[node]){
                    return false;
                }
            }
        }
        }
        return true;
    }
};