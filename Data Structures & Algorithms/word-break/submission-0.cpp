class Solution {
public:
    vector<int> dp;

    bool solve(int i, string &s, unordered_set<string>& st){
        int n = s.size();

        if(i == n)
            return true;

        if(dp[i] != -1)
            return dp[i];

        for(int j = i; j < n; j++){
            string word = s.substr(i, j - i + 1);

            if(st.count(word) && solve(j + 1, s, st))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(
            wordDict.begin(),
            wordDict.end()
        );

        dp.resize(s.size(), -1);

        return solve(0, s, st);
    }
};