class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> counters(n,1);
        
        
        for(int i = 1 ; i < n  ;i++){
            if(ratings[i] > ratings[i-1]){
                counters[i] = counters[i - 1] + 1;
            }
            
            
        }
        
        int sum = counters[n-1];
        
        for(int i = n - 2 ; i >= 0 ;i--){
            if(ratings[i] > ratings[i+1]){
                counters[i] = max(counters[i] , counters[i+1]+1);
            }
            sum+= counters[i];
        }
        
        
        
        
        return sum;
    }
};