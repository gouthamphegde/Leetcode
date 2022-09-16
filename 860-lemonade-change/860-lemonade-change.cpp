class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> counts(3,0);
        
        for(int i = 0 ; i < bills.size() ;i++){
            if(bills[i] == 5){
                counts[0]++;
            }
            if(bills[i] == 10){
                counts[1]++;
                if(counts[0] > 0){
                    counts[0]--;
                }
                else{
                    return false;
                }
            }
            if(bills[i] == 20){
                counts[2]++;
                if(counts[1] > 0){
                    counts[1]--;
                    if(counts[0] > 0){
                        counts[0]--;
                    }
                    else{
                        return false;
                    }
                }
                else if(counts[0]>=3){
                    counts[0]-=3;
                }
                else{
                    return false;
                }
                
            }
        }
        
        return true;
        
    }
};