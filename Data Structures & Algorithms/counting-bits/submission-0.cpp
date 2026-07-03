class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int count=0;
            int x=i;
            while(x){
                count += (x&1);
                x >>= 1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
