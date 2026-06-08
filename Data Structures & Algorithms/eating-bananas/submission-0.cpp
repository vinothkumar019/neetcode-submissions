class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        int ans=high;
        int tol=0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            ans=0;
            for(int i=0;i<n;i++){
                ans += (piles[i] + mid - 1) / mid;
            }
            if(ans <= h){
                tol=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return tol;
    }
};
