
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
                right--;
            }
        }

        return ans;
    }
};
