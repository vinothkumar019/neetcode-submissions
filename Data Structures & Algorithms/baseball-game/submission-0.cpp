class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n=operations.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(operations[i] == "+"){
                if(st.size() >= 2){
                    int temp1=st.top();
                    st.pop();
                    int temp2=st.top();
                    st.pop();
                    st.push(temp2);
                    st.push(temp1);
                    st.push(temp1+temp2);
                }
            }
            else if(operations[i] == "D"){
                if(!st.empty()){
                    int temp=st.top();
                    st.push(temp*2);
                }
            }
            else if(operations[i] == "C"){
                if(!st.empty()) st.pop();
            }
            else if(stoi(operations[i])){
                st.push(stoi(operations[i]));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};