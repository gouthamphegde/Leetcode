class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int mintime = 0;
        
        int i = 0 , j = 1;
        
        while(i < n && j < n){
            if(colors[i] == colors[j]){
                if(neededTime[i] < neededTime[j]){
                    mintime+= neededTime[i];
                    i = j;
                }
                else{
                    mintime+= neededTime[j];
                }
            }
            else{
                i= j;
            }
            j++;
        }
        
        return mintime;
        
      
    }
};