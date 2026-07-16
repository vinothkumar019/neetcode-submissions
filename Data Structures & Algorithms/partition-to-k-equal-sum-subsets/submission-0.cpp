class Solution {
public:
    bool dfs(vector<int>& nums,int index,int target,int k,vector<int> div){
        if(index == nums.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(div[i]+nums[index] <= target){
                div[i] += nums[index];
                if(dfs(nums,index+1,target,k,div)) return true;;
                div[i] -= nums[index];
            }
            if(div[i] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int target=0;
        for(int i:nums){
            sum += i;
        }
        if(sum%k != 0) return false;
        target=sum/k;
        sort(nums.rbegin(),nums.rend());
        vector<int> div(k,0);
        return dfs(nums,0,target,k,div);
    }
};