class Solution {
public:
    int count=0;
    void expand(int l,int r,string& s){
        while(l >=0 && r < s.size() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        int n=s.size();

        for(int i=0;i<n;i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }
        return count;
    }
};
