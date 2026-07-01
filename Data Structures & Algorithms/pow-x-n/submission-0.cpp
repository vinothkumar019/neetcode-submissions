class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        if(n >0){
            for(int i=1;i<=n;i++){
                ans *= x;
            }
        }
        else if(n < 0){
            n=-n;
            for(int i=1;i<=n;i++){
                ans *= x;
            }
            ans = 1/ans;
        }
        else if(n == 0) return 1.0;

        return ans;
    }
};
