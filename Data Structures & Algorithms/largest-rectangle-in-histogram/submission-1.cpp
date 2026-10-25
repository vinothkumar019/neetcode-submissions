
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // Stores indices
        int area = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() &&
                   currHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                area = max(area, height * width);
            }

            st.push(i);
        }

        return area;
    }
};
