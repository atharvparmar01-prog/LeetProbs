class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0;i<gas.size();i++){
            if(gas[i]>cost[i] || (gas[i]>=cost[i] && n==1)){
                int fuel=0;
                for(int j=0;j<=gas.size();j++){
                    fuel+=gas[(j+i)%n];
                    fuel-=cost[(j+i)%n];
                    if(fuel<0){break;}
                }
                if(fuel>=0){return i;}
            }
        }
        return -1;
    }

};