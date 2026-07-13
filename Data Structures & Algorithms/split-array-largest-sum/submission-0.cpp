class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int count = 1;   // At least one subarray
        int sum = 0;

        for (int num : nums) {
            if (sum + num <= maxSum) {
                sum += num;
            } else {
                count++;
                sum = num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};