class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> dp;

    vector<string> dfs(string &s, int start) {

        if (dp.count(start))
            return dp[start];

        vector<string> res;

        if (start == s.size()) {
            res.push_back("");
            return res;
        }

        for (int end = start; end < s.size(); end++) {

            string word = s.substr(start, end - start + 1);

            if (!dict.count(word))
                continue;

            vector<string> suffix = dfs(s, end + 1);

            for (string &str : suffix) {

                if (str.empty())
                    res.push_back(word);
                else
                    res.push_back(word + " " + str);
            }
        }

        return dp[start] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        dict.insert(wordDict.begin(), wordDict.end());

        return dfs(s, 0);
    }
};