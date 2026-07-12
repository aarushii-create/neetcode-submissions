class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), total=0, tank=0;
        int indx=0;
        for(int i=0; i<n; i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            tank+=diff;
            if(tank<0){
                indx=i+1;
                tank=0;
            }
        }
        return total>=0?indx:-1;
    }
};
