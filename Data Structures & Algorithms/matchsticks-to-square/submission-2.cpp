class Solution {
public:
    bool dfs(vector<int>& matchsticks,int index,int target,vector<int> side){
        if(index == matchsticks.size()) return true;

        for(int i=0;i<4;i++){
            if(side[i]+matchsticks[index] > target) continue;
            side[i] += matchsticks[index];
             if(dfs(matchsticks,index+1,target,side))
                return true;
            side[i] -=  matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        int target=0;
        for(int i:matchsticks){
            sum += i;
        }
        if(sum%4 != 0) return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        target=sum/4;
        vector<int> side(4,0);

        return dfs(matchsticks,0,target,side);
    }
};