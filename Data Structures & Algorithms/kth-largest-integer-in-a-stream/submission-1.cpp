class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int n=nums.size();
        for(int i=0;i<n;i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        int top;
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};
