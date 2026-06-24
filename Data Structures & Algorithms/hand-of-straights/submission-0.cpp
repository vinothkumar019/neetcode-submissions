class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        sort(hand.begin(),hand.end());
        unordered_map<int,int> freq;
        for(int i:hand) freq[i]++;

        for(int x:hand){
            if(freq[x] == 0) continue;
            for(int k=0;k<groupSize;k++){
                int card=x+k;
                if(freq[card] == 0) return false;

                freq[card]--;
            }
        }
        return true;

    }
};
