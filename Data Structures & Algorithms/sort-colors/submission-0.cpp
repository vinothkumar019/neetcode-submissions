class Solution {
public:
    void heapify(vector<int>& nums,int n,int i){
        int l=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left < n && nums[left] > nums[l]) l=left;

        if(right < n && nums[right] > nums[l]) l=right;

        if(l != i){
            swap(nums[i],nums[l]);
            heapify(nums,n,l);
        }
    }
    void sortColors(vector<int>& nums) {
        int n=nums.size();

        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>=0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
    }
};