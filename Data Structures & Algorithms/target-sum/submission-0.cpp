class Solution {
public:
    unordered_map<string, int> memo;

    int solve(int i, int sum, int target, vector<int>& nums) {
        if(i == nums.size())
            return (sum == target);

        string key = to_string(i) + "," + to_string(sum);

        if(memo.count(key))
            return memo[key];

        int plus = solve(i + 1,
                         sum + nums[i],
                         target,
                         nums);

        int minus = solve(i + 1,
                          sum - nums[i],
                          target,
                          nums);

        return memo[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, target, nums);
    }
};