class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> st(nums.begin(),nums.end());
        int maxi=0;
        int count;
        for(auto i:st){
            if(st.find(i-1) == st.end()){
                count=1;
                while(st.find(i+1) != st.end()){
                    count++;
                    i++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;

    }
};
