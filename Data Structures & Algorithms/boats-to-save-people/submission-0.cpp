class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int left=0;
        int right=n-1;
        int count=0;
        while(left <= right){
            int sum=people[left]+people[right];
            if(sum <= limit){
                left++;
            }
            right--;
            count++;
        }
        return count;
    }
};