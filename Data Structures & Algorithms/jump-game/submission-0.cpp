class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i > far) return false;

            far=max(far,i+nums[i]);
        }
        return true;
    }
};
