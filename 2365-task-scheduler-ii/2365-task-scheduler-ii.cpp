class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int , long long> mpp;
        
        
        long long days = 0;
        
        for(int i = 0 ; i < tasks.size() ;i++){
            if(mpp[tasks[i]]){
                if(days - mpp[tasks[i]] >=space){
                    days+=1;
                }
                else{
                    days+= (space-(days-mpp[tasks[i]]));
                    days++;
                    
                }
                mpp[tasks[i]] = days;
            }
            
            if(!mpp[tasks[i]]){
                days++;
                mpp[tasks[i]] = days;
            }
        }
        
        return days;
    }
};