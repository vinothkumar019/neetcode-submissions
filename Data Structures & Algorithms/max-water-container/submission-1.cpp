class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int maxi=INT_MIN;
        
        while(i<j){
            int count=0;
            count = min(heights[i], heights[j]) * (j - i);
            maxi=max(maxi,count);
            if(heights[i] < heights[j]){
                 i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};
