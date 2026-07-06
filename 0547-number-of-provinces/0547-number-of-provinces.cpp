class Solution {
private:
    void DFS(int node, vector<vector<int>>& adjLS, vector<int>& visited) {
        visited[node] = 1;

        for (auto it : adjLS[node]) {
            if (!visited[it]) {
                DFS(it, adjLS, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();

        vector<vector<int>> adjLS(V);

        // Convert adjacency matrix into adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }

        vector<int> visited(V, 0);

        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                DFS(i, adjLS, visited);
            }
        }

        return provinces;
    }
};