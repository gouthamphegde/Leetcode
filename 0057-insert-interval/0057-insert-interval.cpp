class Solution {
    
    void mergeIntervals(vector<vector<int>>& intervals , vector<vector<int>>& ans){
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ;i++){
            if(ans.back()[1] >= intervals[i][0]){
                if(intervals[i][1] >= ans.back()[1]){
                    ans.back()[1] = intervals[i][1];
                }
                
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        int i = 0 ;
        
        for(; i < intervals.size() ;i++){
            if(intervals[i][0] <= newInterval[0]){
                ans.push_back(intervals[i]);
                cout << intervals[i][0] << " " << intervals[i][1] << endl;
            }
            else{
                break;
            }
        }
        
        
        ans.push_back(newInterval);
        cout << newInterval[0] << " " << newInterval[1] << endl;
        
        for(;i < intervals.size() ; i++){
            ans.push_back(intervals[i]);
            cout << intervals[i][0] << " " << intervals[i][1] << endl;

            
        }
        
        vector<vector<int>> result;
        
        mergeIntervals(ans , result);
        
        return result;
    }
};