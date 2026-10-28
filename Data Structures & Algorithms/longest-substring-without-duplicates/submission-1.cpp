class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left=0;
        int ans=0;
        int n=s.size();
        for(int right=0;right<n;right++){
            if(mp.find(s[right]) != mp.end()){
                left=max(left,mp[s[right]]+1);
            }
            mp[s[right]]=right;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
