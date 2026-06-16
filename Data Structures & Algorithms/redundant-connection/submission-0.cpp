class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
    void unite(int a,int b){
        int pa=find(a);
        int pb=find(b);
        parent[pb]=pa;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;     
        }
        vector<int> res;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(find(u) == find(v)){
                res.push_back(u);
                res.push_back(v);
                return res;
            }
            unite(u,v);

        }
        return res;
    }
};
