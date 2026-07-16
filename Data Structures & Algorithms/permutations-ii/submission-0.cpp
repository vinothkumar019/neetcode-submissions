class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,vector<bool> vis,vector<int> curr){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            if(i >0 && nums[i-1] == nums[i] && !vis[i-1]) continue;
            vis[i]=true;
            curr.push_back(nums[i]);
            dfs(nums,vis,curr);
            curr.pop_back();
            vis[i]=false;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> vis(nums.size(),false);
        vector<int> curr;
        dfs(nums,vis,curr);
        return ans;
    }
};