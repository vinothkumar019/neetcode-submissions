class Solution {
public:
    priority_queue<int> pq;
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
        
    }
};
