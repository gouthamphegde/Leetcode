class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        
        int ans = 0;
        
        int n = intervals.size();
        vector<int> last = intervals[0];
        for(int i = 1 ; i < n; i++){
            if(intervals[i][0] < last[1]){
                if(intervals[i][1] < last[1]){
                    last = intervals[i];
                }
                ans++;
            }
            else{
                last=intervals[i];
            }
        }
        
        return ans;
    }
};