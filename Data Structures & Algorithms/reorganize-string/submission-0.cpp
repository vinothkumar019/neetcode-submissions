class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>> pq;
        int maxFreq=0;
        for(char ch:s){
            freq[ch]++;
            maxFreq=max(maxFreq,freq[ch]);
        }
        if(maxFreq > (n+1)/2) return "";
        pair<int,char> prev={0,'#'};
        for(auto &it:freq){
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            ans += curr.second;
            curr.first--;
            if(prev.first > 0){
                pq.push(prev);
            }
            prev=curr;
        }
        return ans;
    }
};