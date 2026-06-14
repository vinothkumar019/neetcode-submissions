class Solution {
public:
    vector<int> states;
    vector<vector<int>> adj;
    vector<int> order;
    bool dfs(int courses){
        if(states[courses] == 1) return false;

        if(states[courses] == 2) return true;

        states[courses]=1;
        for(auto e:adj[courses]){
            if(!dfs(e)) return false;
        }
        states[courses]=2;
        order.push_back(courses);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        states.resize(numCourses,0);
        adj.resize(numCourses);
        for(auto& nei:prerequisites){
            int u = nei[0];
            int v = nei[1];
            //adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i)) return {};
        }
        reverse(order.begin(),order.end());

        return order;

    }
};
