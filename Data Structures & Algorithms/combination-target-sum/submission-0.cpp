class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int count=0;
    void dfs(vector<int> nums,int target,int idx){
        if(nums.size() == idx || target < 0){
            return;
        }
         if(target == 0) {
            ans.push_back(path);
            return;
         }
        path.push_back(nums[idx]);
        dfs(nums,target-nums[idx],idx);
        path.pop_back();
        dfs(nums,target,idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,target,0);
        return ans;
    }
};
