class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(char ch : s){
            mp1[ch]++;
        }
        for(char ch : t){
            mp2[ch]++;
        }

        if(mp1 == mp2) return true;

        return false;
    }
};
