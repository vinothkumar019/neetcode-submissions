class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0)pq.push({a,'a'});
        if(b > 0)pq.push({b,'b'});
        if(c > 0)pq.push({c,'c'});
        string ans;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(ans.size() >= 2 &&
            ans.back() == curr.second &&
            ans[ans.size() - 2] == curr.second){
                if(pq.empty()) break;
                auto curr1=pq.top();
                pq.pop();
                
                ans += curr1.second;
                curr1.first--;

                if(curr1.first > 0){
                    pq.push(curr1);
                }
                pq.push(curr);
            }
            else{
                ans += curr.second;
                curr.first--;
                if(curr.first >0) pq.push(curr);
            }

        }
        return ans;
    }
};