class Solution {
public:
    vector<int> dp;
    int solve(int i,string &s){
        int n=s.size();
        if(i == n) return 1;
        else if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int ans = solve(i+1,s);
        if(i+1 < n){
        int val = (s[i]-'0')*10 + (s[i+1]-'0');
        if(val >= 10 && val <= 26) ans+=solve(i+2,s);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return solve(0,s);
    }
};
