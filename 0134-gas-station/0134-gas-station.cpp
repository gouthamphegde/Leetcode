#include <bits/stdc++.h>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0;
        int totalcost = 0;
        
        totalgas = accumulate(gas.begin() , gas.end() , 0);
        totalcost = accumulate(cost.begin() , cost.end(),0);
        
        
        if(totalgas < totalcost){
            return -1;
        }
        
        int tank = 0 , start = 0;
        
        for(int i = 0 ; i < n ;i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        
        return start;
    }
};