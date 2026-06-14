class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<bool>& visited,int i){
        visited[i]=true;
        for(auto e:adj[i]){
            if(!visited[e]) dfs(adj,visited,e);
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);

        int comp=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                comp++;
                dfs(adj,visited,i);
            }
        }
        return comp;
    }
};
