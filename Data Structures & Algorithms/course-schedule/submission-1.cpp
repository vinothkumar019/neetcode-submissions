class Solution {
public:
    vector<int> states;
    vector<vector<int>> adj;
    bool dfs(int c){
        if(states[c] == 1) return false;
        if(states[c] == 2) return true;

        states[c]=1;

        for(auto next:adj[c]){
            if(!dfs(next)) return false;
        }
        states[c]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       // if(prerequisites.size() != numCourses-1) return false;

        states.resize(numCourses,0);
        adj.resize(numCourses);
        for(auto& p : prerequisites){

    int course = p[0];
    int prereq = p[1];

    adj[prereq].push_back(course);
}
        for(int i=0;i<numCourses;i++){
            if(!dfs(i)) return false;
        }
        return true;

    }
};
