class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int count=0;
    void dfs(vector<int>& nums, int target, int idx){

    if(target == 0){
        ans.push_back(path);
        return;
    }

    if(target < 0)
        return;

    for(int i = idx; i < nums.size(); i++){

        if(i > idx && nums[i] == nums[i-1])
            continue;

        if(nums[i] > target)
            break;

        path.push_back(nums[i]);

        dfs(nums, target - nums[i], i + 1);

        path.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dfs(nums,target,0);
        return ans;
    }
};
