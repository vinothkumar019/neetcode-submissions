class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int m=cost.size();
        int totalgas=0;
        int totalcost=0;
        for(int g:gas) totalgas += g;
        for(int c:cost) totalcost += c;

        if(totalgas < totalcost) return -1;
        int start=0;
        int count=0;
        for(int i=0;i<n;i++){
            count += gas[i]-cost[i];
            if(count < 0){
                start=i+1;
                count=0;
            }
        }
        return start;
    }
};
