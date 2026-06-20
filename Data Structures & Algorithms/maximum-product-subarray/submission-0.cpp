class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < 0)
                swap(curMax, curMin);

            curMax = max(nums[i], nums[i] * curMax);
            curMin = min(nums[i], nums[i] * curMin);

            ans = max(ans, curMax);
        }

        return ans;
    }
};