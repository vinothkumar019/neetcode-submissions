class Solution {
public:
    priority_queue<pair<int, vector<int>>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto& point:points){
            int dist = point[0] * point[0] +
           point[1] * point[1];
           p.push({dist, point});
            if(p.size() > k)
            p.pop();
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};
