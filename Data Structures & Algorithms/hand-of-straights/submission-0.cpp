class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        map<int, int> freq;
        for(auto num:hand){
            freq[num]++;
        }
        sort(hand.begin(), hand.end());
        int prev=hand[0];
        hand.erase(hand.begin());
        freq[prev]--;
        if(!freq[prev]) freq.erase(prev);
        int k=groupSize-1;
        for(auto num:hand){
            if(k){
                if(freq[prev+1]){
                    cout<<prev+1;
                    freq[prev+1]--;
                    if(!freq[prev+1]) freq.erase(prev+1);
                    k--;
                    prev++;
                }
                else return false;
            }
            else{
                k=groupSize;
                prev=freq.begin()->first;
                cout<<prev;
                freq[prev]--;
                if(!freq[prev]) freq.erase(prev);
                k--;
            }
        }
        return true;
    }
};
