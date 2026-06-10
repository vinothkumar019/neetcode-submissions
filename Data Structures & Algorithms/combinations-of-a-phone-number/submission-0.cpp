class Solution {
public:
    unordered_map<char,string> mp = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};
    string curr;
    vector<string> ans;
    void dfs(int idx,string &digits){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        string letter=mp[digits[idx]];
        for(char ch:letter){
            curr.push_back(ch);
            dfs(idx+1,digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        dfs(0,digits);
        return ans;
    }
};
