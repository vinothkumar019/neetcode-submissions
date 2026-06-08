class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first=strs[0];

        for(int i=1;i<strs.size();i++){
            while(strs[i].find(first) != 0){
                first.pop_back();

                if(first.empty()) return "";
            }
        }
        return first;
    }
};