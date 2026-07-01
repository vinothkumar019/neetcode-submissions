class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        long  long count=0;
        int mul=1;
        int n=digits.size();
        if(digits[n-1] != 9){ 
            digits[n-1] +=1;
            return digits;
        }
        else{
            for(int i=n-1;i>=0;i--){
                count += digits[i]*(mul);
                mul *= 10;
            }
            count += 1;
            while(count > 0){
                ans.push_back(count%10);
                count /= 10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
