class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days) {

    int daysUsed = 1;
    int currentWeight = 0;

    for (int w : weights) {

        if (currentWeight + w <= capacity) {
            currentWeight += w;
        }
        else {
            daysUsed++;
            currentWeight = w;
        }
    }

    return daysUsed <= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        for(int i:weights){
            low=max(low,i);
            high += i;
        }
        while(low <= high){
            int mid=low+(high-low)/2;

            if(canShip(weights,mid,days)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;

    }
};