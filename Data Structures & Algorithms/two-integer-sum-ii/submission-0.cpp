class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(numbers[i]+numbers[j] == target){
                res.push_back(i+1);
                res.push_back(j+1);
                }
            }
        }
        return res;
    }
};
