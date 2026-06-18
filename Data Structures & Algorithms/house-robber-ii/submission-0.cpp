class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int next1 = 0;
        int next2 = 0;

        for(int i = r; i >= l; i--) {
            int cur = max(nums[i] + next2, next1);
            next2 = next1;
            next1 = cur;
        }

        return next1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        return max(
            solve(nums, 0, n - 2),
            solve(nums, 1, n - 1)
        );
    }
};