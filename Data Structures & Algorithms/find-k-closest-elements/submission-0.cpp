class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> ans;
        int i=0;
        int j=n-1;
        while(j-i+1 > k){
                if(abs(arr[i]-x) > abs(arr[j]-x)){
                    i++;
                }
                else j--;
            }
        for(int k=i;k<=j;k++){
            ans.push_back(arr[k]);
        }
        return ans;
    }
};