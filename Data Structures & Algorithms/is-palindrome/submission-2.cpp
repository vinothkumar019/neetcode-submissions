class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        for(char &c : s){
        c = tolower(c);
        }
        int i=0;
        int j=n-1;
        while(i<j){
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }
            if(s[i] != s[j]) return false;

            i++;
            j--;
        }
        return true;
    }
};
