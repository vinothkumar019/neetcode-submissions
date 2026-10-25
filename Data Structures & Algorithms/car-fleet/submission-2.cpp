class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> pq;
        int n=position.size();
        for(int i=0;i<n;i++){
            double time=double(target-position[i])/speed[i];
            pq.push_back({position[i],time});
        }
        sort(pq.rbegin(),pq.rend());
        double last=0;
        int ans=0;
        for(auto &i:pq){
            if(i.second > last){
                ans++;
                last=i.second;
            }
        }
        return ans;
    }
};
