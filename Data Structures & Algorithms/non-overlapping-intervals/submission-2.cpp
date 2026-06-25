class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> prev=intervals[0];
        int count=0;
        for(int i=1;i<n;i++){
            vector<int> cur=intervals[i];
            if(cur[0] < prev[1]) {
                count++;
                prev[1] = min(prev[1], cur[1]);
            }
            else {
                prev=cur;
            }

        }
        return count;

    }
};
