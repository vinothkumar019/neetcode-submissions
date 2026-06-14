class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<bool>& visited,int node){
        visited[node]=true;
        for(auto nei:adj[node]){
             if(!visited[nei]) dfs(adj,visited,nei);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        vector<vector<int>> adj(n);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        dfs(adj,visited,0);
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};
