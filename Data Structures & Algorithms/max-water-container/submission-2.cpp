class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxi=0;
        
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
