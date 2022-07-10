class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int previous = 0;
        int previous2 = 0;
        
        for(int i = 2 ; i < cost.size()+1 ;i++){
            int left = previous + cost[i-1];
            
            int right = previous2 + cost[i-2];
            
            
            int ans = min(left , right);
            
            previous2 = previous;
            previous = ans;
            
            
        }
        
        
        return previous;
        
    }
};