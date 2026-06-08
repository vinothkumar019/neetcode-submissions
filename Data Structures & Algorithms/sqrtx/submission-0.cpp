class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        int ans=0;
        while(low <= high){
            int num=low+(high-low)/2;
            long long s= 1LL * num * num;
            if(s==x) return num;
            if(s < x){
                ans=num;
                low=num+1;
            }
            if(s > x) high=num-1;
        }
        return ans;
    }
};