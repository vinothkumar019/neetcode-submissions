class Solution {
public:
    int sum=0;
    void dfs(vector<int>& nums,int index,int currXor){
        if(index == nums.size()){
            sum += currXor;
            return;
        }
        dfs(nums,index+1,currXor xor nums[index]);
        dfs(nums,index+1,currXor);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        dfs(nums,0,0);
        return sum;
    }
};